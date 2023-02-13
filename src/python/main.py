import sys
sys.path.append('build/')
import fastsim
import math
import time

if __name__ == "__main__":
    settings = fastsim.Settings(sys.argv[1])
    map = settings.map()
    robot = settings.robot()

    d = fastsim.Display(map, robot)

    for i in range(1000):
        d.update()
        robot.move(1.0, 1.1, map)
        print("Step ", i, " robot pos: x = ", robot.get_pos().x(), "    y = ", robot.get_pos().y(), "    theta = ", robot.get_pos().theta())
        time.sleep(1000/1000000.0)
