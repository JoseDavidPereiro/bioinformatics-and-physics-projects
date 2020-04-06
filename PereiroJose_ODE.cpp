#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

double Fx(double vy, double vz, double By, double Bz){
  return vy*Bz-vz*By;
}

double Fy(double vx, double vz, double Bx, double Bz){
  return -(vx*Bz - vz*Bx);
}

double Fz(double vx, double vy, double Bx, double By){
  return vx*By-vy*Bx;
}

double dx(double vx){
  return vx;
}

double dy(double vy){
  return vy;
}

double dz(double vz){
  return vz;
}



int main(){
  
  double Bx = 0.0;
  double By = 0.0;
  double Bz = 3.0;

  double q = 1.5;
  double m = 2.5;

  double x = 1.0;
  double y = 0.0;
  double z = 0.0;

  double vx  = 0.0;
  double vy = 1.0;
  double vz = 2.0;

  double dt = 0.01;
  double T = 10;

  int n = T/dt;

  for(int i = 0; i<n; i++){

    double t = i*dt;
    /*cout << Fx(vy,vz,By,Bz) << ' ' << Fy(vx,vz,Bx,Bz) << ' ' << Fz(vx,vy,Bx,By) << endl;*/
    cout << t << ' ' << x << ' ' << y << ' ' << z << endl; 
    double k1_vx = q/m*Fx(vy,vz,By,Bz);
    double k1_vy = q/m*Fy(vx,vz,Bx,Bz);
    double k1_vz = q/m*Fz(vx,vy,Bx,By);
    double k1_x = dx(vx);
    double k1_y = dy(vy);
    double k1_z = dz(vz);

    double k2_vx = q/m*Fx(vy+k1_vy*dt/2.0 , vz+k1_vz*dt/2.0 , By,Bz);
    double k2_vy = q/m*Fy(vx+k1_vx*dt/2.0 , vz+k1_vz*dt/2.0 , Bx,Bz);
    double k2_vz = q/m*Fz(vx+k1_vx*dt/2.0 , vy+k1_vy*dt/2.0 , Bx,By);
    double k2_x = dx(vx+k1_vx*dt/2.0);
    double k2_y = dy(vy + k1_vy*dt/2.0);
    double k2_z = dz(vz + k1_vz*dt/2.0);

    double k3_vx = q/m*Fx(vy+k2_vy*dt/2.0 , vz+k2_vz*dt/2.0 , By,Bz);
    double k3_vy = q/m*Fy(vx+k2_vx*dt/2.0 , vz+k2_vz*dt/2.0 , Bx,Bz);
    double k3_vz = q/m*Fz(vx+k2_vx*dt/2.0 , vy+k2_vy*dt/2.0 , Bx,By);
    double k3_x = dx(vx + k2_vx*dt/2.0);
    double k3_y = dy(vy + k2_vy*dt/2.0);
    double k3_z = dz(vz + k2_vz*dt/2.0);

    double k4_vx = q/m*Fx(vy+k3_vy*dt , vz+k3_vz*dt , By,Bz);
    double k4_vy = q/m*Fy(vx+k3_vx*dt , vz+k3_vz*dt , Bx,Bz);
    double k4_vz = q/m*Fz(vx+k3_vx*dt , vy+k3_vy*dt , Bx,By);
    double k4_x = dx(vx + k3_vx*dt);
    double k4_y = dy(vy + k3_vy*dt);
    double k4_z = dz(vz + k3_vz*dt);

    x += (k1_x+2*k2_x+2*k3_x+k4_x)*dt/6.0;
    y += (k1_y+2*k2_y+2*k3_y+k4_y)*dt/6.0;
    z += (k1_z+2*k2_z+2*k3_z+k4_z)*dt/6.0;

    vx += (k1_vx+2*k2_vx+2*k3_vx+k4_vx)*dt/6.0;
    vy += (k1_vy+2*k2_vy+2*k3_vy+k4_vy)*dt/6.0;
    vz += (k1_vz+2*k2_vz+2*k3_vz+k4_vz)*dt/6.0;
  }


}
