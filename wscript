#!/usr/bin/env python
# encoding: utf-8

import copy
import os, sys
import fnmatch
import glob
sys.path.insert(0, sys.path[0]+'/waf_tools')

VERSION='0.0.1'
APPNAME='libfastsim'
srcdir = '.'
blddir = 'build'

import pybind

def options(opt):
    opt.load('compiler_cxx boost waf_unit_test')
    opt.load('compiler_c')
    opt.load('sdl')
    opt.load('pybind')

    opt.add_option('--python', action='store_true', help='compile python bindings', dest='pybind')
    opt.add_option('--cxx-version', action='store', help='CXX version', dest='cxx_version', default=None)

def configure(conf):
    print("configuring b-optimize")
    conf.load('compiler_cxx boost waf_unit_test')
    conf.load('compiler_c')
    conf.load('sdl')
    if conf.options.pybind:
        conf.load('python')
        conf.load('pybind')

    conf.check_sdl(required=False)

    conf.env['BUILD_PYTHON'] = False
    if conf.options.pybind:
        conf.check_python_version((2, 7))
        conf.check_python_headers(features='pyext')
        # conf.check_python_module('numpy')
        conf.check_pybind11(required=True)
        conf.env['BUILD_PYTHON'] = True

    common_flags = "-Wall"

    cxxflags = conf.env['CXXFLAGS']
    #    conf.check_boost(lib='',
    #            min_version='1.35')

    # release
    cxx_version = ' '
    if conf.options.cxx_version:
        cxx_version = f'-std={conf.options.cxx_version}'
    opt_flags = common_flags + ' -O3 -fPIC ' + cxx_version
    conf.env['CXXFLAGS'] = cxxflags + opt_flags.split(' ')
    print(conf.env['CXXFLAGS'])

def build(bld):
    #### compilation of libfastsim
    files = []
    py_files = []
    for root, dirnames, filenames in os.walk(bld.path.abspath()+'/src/'):
        for filename in fnmatch.filter(filenames, '*.cpp'):
            ffile = os.path.join(root, filename)
            if 'main.cpp' in ffile:
                continue
            if 'src/python' in ffile:
                py_files.append(ffile)
            else:
                files.append(ffile)

    files = [f[len(bld.path.abspath())+1:] for f in files]
    libfastsim_srcs = " ".join(files)
    py_files = [f[len(bld.path.abspath())+1:] for f in py_files]
    libfastsim_py_srcs = " ".join(py_files)

    libs = 'BOOST SDL'

    bld.program(features = 'cxx cxxstlib',
                source = libfastsim_srcs,
                includes = './src',
                uselib = libs,
                target = 'fastsim')
    #### end

    #### compilation of the Python3 bindings
    if bld.env['BUILD_PYTHON'] == True:
        # fix for native flags from pyext
        native_flags = ['-march=x86-64', '-mtune=generic']
        for flag in native_flags:
            if flag in bld.env['CXXFLAGS_PYEXT']:
                bld.env['CXXFLAGS_PYEXT'].remove(flag)
        for flag in bld.env['CXXFLAGS']:
            if flag in bld.env['CXXFLAGS_PYEXT']:
                bld.env['CXXFLAGS_PYEXT'].remove(flag)

        bld.program(features = 'c cshlib pyext',
                    source = './src/python/pyfastsim.cc ' + libfastsim_py_srcs,
                    includes = './src',
                    uselib = 'PYBIND11 ' + libs,
                    use = 'fastsim',
                    target = 'pyfastsim')
    #### end

    #### installation (waf install)
    install_files = []
    for root, dirnames, filenames in os.walk(bld.path.abspath()+'/src/'):
        for filename in fnmatch.filter(filenames, '*.hpp'):
            ffile = os.path.join(root, filename)
            if 'src/python' in ffile:
                continue
            install_files.append(os.path.join(root, filename))
    install_files = [f[len(bld.path.abspath())+1:] for f in install_files]

    for f in install_files:
        end_index = f.rfind('/')
        if end_index == -1:
            end_index = len(f)
        bld.install_files('${PREFIX}/include/libfastsim' + f[4:end_index], f)
    bld.install_files('${PREFIX}/lib', blddir + '/libfastsim.a')
