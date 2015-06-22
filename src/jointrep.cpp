#include "ros/ros.h"
#include "sensor_msgs/JointState.h"
#include "geometry_msgs/Vector3.h"//rosserial pasa de float64 a float32 pero la perdida de precision es minima


const char* InfJointName="YAW";
const char* SupJointName="PITCH";
const int numberMovableJoints=6;

static ros::Publisher pub;//para tener visibilidad dentro de la funcion jointCallback

void jointCallback(const sensor_msgs::JointState::ConstPtr& msg)
{ 
  static int InfJointPos=0;//mantiene el valor en diferentes llamadas a la funcion
  static int SupJointPos=0; 
  static bool poscalc=false;//se pone a true cuando la posicion del ector ha sido calculada

  for(int i=0; i<=numberMovableJoints-1 && !poscalc; i++){
    if(strcmp(InfJointName,msg->name[i].c_str())==0)//strcmp
      InfJointPos=i;
    if(strcmp(SupJointName,msg->name[i].c_str())==0)
      SupJointPos=i;
  }
  poscalc=true;
  //ROS_INFO("I heard: [%f]", msg->position[InfJointPos]);
  //ROS_INFO("I heard: [%f]", msg->position[SupJointPos]);
  geometry_msgs::Vector3 serv;
  serv.x=msg->position[InfJointPos];
  serv.y=msg->position[SupJointPos];
  pub.publish(serv);
}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "jointrepnode");

  
  ros::NodeHandle n;

  
  ros::Subscriber sub = n.subscribe("joint_states", 1000, jointCallback);

  pub = n.advertise<geometry_msgs::Vector3>("servoinfo", 1000);

  
  ros::spin();

  return 0;
}
