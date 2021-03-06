/*vex-vision-config:begin*/
#include "vex.h"
vex::vision::signature REDBALL = vex::vision::signature (1, 10355, 11227, 10791, -1061, -113, -587, 2.9, 0);
vex::vision::signature BLUEBALL = vex::vision::signature (2, -4633, -3855, -4244, 11943, 13641, 12792, 3.1, 0);
vex::vision::signature SIG_3 = vex::vision::signature (3, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_4 = vex::vision::signature (4, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_5 = vex::vision::signature (5, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_6 = vex::vision::signature (6, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_7 = vex::vision::signature (7, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision Vision1 = vex::vision (vex::PORT1, 50, REDBALL, BLUEBALL, SIG_3, SIG_4, SIG_5, SIG_6, SIG_7);
/*vex-vision-config:end*/