#include <algorithm>
 #include<iostream>
#include<cmath>
#include <fstream>

using std::cout;
using std::endl;
using std::ofstream;

float rho_m = 4.0;
int N = 40;

float rho_0(int i){
  float resp = 0.0;
  if( (i < N/2 ) and (i > N/4)){
    resp = rho_m;
  }
  else if(i == N/2){
    resp = rho_m/2.0;
  }
  else{
    resp = 0.0;
  }
  return resp;
}

int main(){

  /* Juan Pablo Montoya nacio el 20 de septiembre de 1975 en Bogota, y participo en la formula 1 entre 2001 y 2006 */
  float L = 2000.0;
  float *x = new float[N];
  float *rho = new float[N];
  float *rho_ant = new float[N];
  float t = 0.8;
  float tau = 0.04;
  int N_t = t/tau;
  float v_max = 90.0;
  float dx = L/((float)N);



  for(int i = 0; i < N; i++){
    x[i] = -1000.0+i*dx;
    rho[i] = rho_0(i);
    rho_ant[i] = rho_0(i);
  }

  ofstream archivo;
  archivo.open("inicial.txt");
  for(int i = 0; i<N;i++){
    archivo << x[i] << ' ' << rho[i] << endl;
  }
  archivo.close();

  archivo.open("inicialnorm.txt");
    for(int i = 0; i<N;i++){
      archivo << x[i] << ' ' << rho[i]/rho_m << endl;
    }
  archivo.close();


  for(int j = 0; j<N_t; j++){
    for(int i = 1; i < N-1; i++){
      float d = (rho_ant[i+1] - rho_ant[i-1])/(2.0*dx);
      rho[i] = rho_ant[i] - v_max*tau*(1.0 - 2.0*rho_ant[i]/rho_m)*d;
    }
    
    for(int i = 0; i < N; i++){
      rho_ant[i] = rho[i];
    }
    cout << rho[N/4] << endl;
  }
  archivo.open("final.txt");
  for(int i = 0; i<N;i++){
    archivo << x[i] << ' ' << rho[i] << endl;
  }
  archivo.close();

  float *final = std::max_element(rho, rho+N);
  float m_f = *(final);

  archivo.open("finalnorm.txt");
    for(int i = 0; i<N;i++){
      archivo << x[i] << ' ' << rho[i]/m_f << endl;
    }
  archivo.close();


}
