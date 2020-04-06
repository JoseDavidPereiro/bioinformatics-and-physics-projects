#include<iostream>
#include<cmath>
#include <fstream>
#include<algorithm>

using std::cout;
using std::endl;
using std::ofstream;

float a_inicial(float x, float t, float x_0, float c, float sigma, float k){
  float y = x - x_0 -c*t;
  float resp = cos(k*y)*exp(-pow(y,2)/(2*sigma*sigma));
  return resp;
}

float L_W(float h, float c, float a_prev, float a_next, float a_now, float tau){
  
  float alg = -(c/(2*h))*(a_next - a_prev) + c*c/(2*h*h)*(a_next + a_prev - 2*a_now);
  float resp = alg*tau + a_now;
  return resp;

}

int main(){
  float pi = 3.141592;
  float c = 1;
  float x_0 = 0;
  float L = 3;
  float sigma = 0.1;
  float k = pi/sigma;
  float t = 0.02;
  float tau = 0.0001;
  int n = 50;


  float *x = new float[n];
  float *a_0 = new float[n];
  float *a = new float[n];

  float dx = L/(float)n;
  for(int i = 0; i<n;i++){
    x[i] = i*dx - L/2.0;
    a_0[i] = a_inicial(x[i],0.0,x_0,c,sigma,k);
    a[i] = a_0[i];
  }

  float *inicial = std::max_element(a_0,a_0+n);
  float m_i = *(inicial);

  ofstream archivo;
  archivo.open("inicial.txt");
  for(int i = 0; i<n;i++){
    archivo << x[i] << ' ' << a_0[i]/m_i << endl;
  }
  archivo.close();

  float t_i = 0;

  while(t_i < t){
    for(int i  = 1; i < n-1; i++){
      a[i] = L_W(dx,c,a[i-1],a[i+1],a[i],tau);
    }
    t_i += tau;
  }

  float*final = std::max_element(a,a+n);
  float m_f = *(final);

  /*ofstream archivo_2;*/
  archivo.open("final.txt");
  for(int i = 0; i<n;i++){
    archivo << x[i] << ' ' << a[i]/m_f << endl;
  }
  archivo.close();
  
  cout << "La solucion es inestable para tau de 0.015" << endl;
  

}
