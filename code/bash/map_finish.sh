#!/bin/bash
rosrun map_server map_server -f map
cp ~/map.pgm ~/team108_ws/src/team_108/maps/
cp ~/map.yaml ~/team108_ws/src/team_108/maps/
