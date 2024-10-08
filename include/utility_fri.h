
// Set of Utility functions for FRI

#pragma once
#include <ros/ros.h>
#include <ros/package.h>
#include <FastResearchInterface.h>
#include <FastResearchInterfaceTest.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <errno.h>
#include <fstream>
#include <vector>
#include <OSAbstraction.h>
#include "dhdc.h"
#include "drdc.h"
#include <signal.h>
#include "vsds_base.h"
#include "min_jerk.h"

namespace utility_fri {


#ifndef LWR_JNT_NUM
#define LWR_JNT_NUM 7
#endif


#ifndef PI
#define PI	3.1415926535897932384626433832795
#endif

#ifndef NUMBER_OF_CYCLES_FOR_QUAULITY_CHECK
#define NUMBER_OF_CYCLES_FOR_QUAULITY_CHECK		2000
#endif

#define SIZE_OF_TRANSFER_STRING					32
#define LINEAR_VISCOSITY   30.0
#define MIN_STIFFNESS 0.01


#define NUMBER_OF_CART_DOFS	6
#define NUMBER_OF_JOINTS		7

using namespace std;
using namespace StiffnessProfiles;
using namespace GeneralFunction ;
using  namespace  Eigen;


int startCartImpedanceCtrl(FastResearchInterface *fri, float *commCartPose) ;
int HD_gravityCompensation() ;
int startJointImpedanceCtrl(FastResearchInterface *fri, float *commJointPosition) ;
Mat GetRotationMatrix(float *CartPose) ;
Vec GetTranslation(float *CartPose) ; 
Mat Convert_Jacobian_2Mat(float ** Jacobian) ;
Mat Convert_MassMat_2Mat(float ** Mass) ;
Vec float_2_Vec(float *inp,int size) ;
Mat Tool_2_World_Jacobian(Mat Jac_tool,Mat Rot) ;
void Set_Desired_Pose_FRI(Mat Rot_d,Vec x_d,float *CartPose_d) ;
Vec Quart_Orient_err(Mat R_a, Mat R_d);
vector< std::vector <float> > Kuka_MoveCartesian_MinJerk(FastResearchInterface *FRI, float tot_time, float dt, Vec x_df) ;
int CartesianGravityCompensation(FastResearchInterface *FRI, float tot_time) ;
int JointGravityCompensation(FastResearchInterface *FRI, float tot_time) ;
int CartesianGravityCompensation_YZ(FastResearchInterface *FRI, float tot_time) ;

Vec ApplyDisturbance(realtype F_distMag,realtype t,realtype t_init,realtype t_final, Vec Des_vel) ;
}
