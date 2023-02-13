import sys
sys.path.append('/Users/tsac/RL/libfastsim/build')
import fastsim
import math
# int main()
# {
#   try
#     {
#       using namespace fastsim;
#       boost::shared_ptr<Map> m = boost::shared_ptr<Map>(new Map("cuisine.pbm", 600));
#       m->add_goal(Goal(100, 100, 10, 0));
#       Robot r(20.0f, Posture(200, 200, 0));
#       r.add_laser(Laser(M_PI / 4.0, 100.0f));
#       r.add_laser(Laser(-M_PI / 4.0, 100.0f));
#       r.add_laser(Laser(0.0f, 100.0f));
#       r.add_radar(Radar(0, 4));
#       Display d(m, r);

#       float x = 30;
#       for (int i = 0; i < 10000; ++i)
# 	{
# 	  d.update();
# 	  r.move(1.0, 1.1, m);
# 	}
#     }
#   catch (fastsim::Exception e)
#     {
#       std::cerr<<"error : "<<e.get_msg()<<std::endl;
#     }
#   return 0;
# }

m = fastsim.Map(fastsim.Map("/Users/tsac/RL/libfastsim/worlds/cuisine.pbm", 600))
m.add_goal(fastsim.Goal(100, 100, 10, 0))
r = fastsim.Robot(20., fastsim.Posture(200, 200, 0))
r.add_laser(fastsim.Laser(math.pi / 4.0, 100.0))
r.add_laser(fastsim.Laser(-math.pi / 4.0, 100.0))
r.add_laser(fastsim.Laser(0.0, 100.0))
r.add_radar(fastsim.Radar(0, 4, True))
# d = fastsim.Display(m, r)


x = 30.0
for i in range(1000):
    # d.update()
    r.move(1.0, 1.1, m, True)
