#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;

int main(int argc, char* argv[]){

  string file = argv[1];
  ifstream input;

  double L = 1;
  double c = 300;
  double dx = 0.01;
  double dt = dx/(2*c);
  double t = 0.06;
  double q = pow(c*dt/dx,2); /* q = c^2dt^2/dx^2*/


  int n = L/dx;
  int N_t = t/dt;
  double **phi_inicial = new double*[n];
  double **phi = new double*[n];
  double **phi_next = new double*[n];

  double **phi_inicial_2 = new double*[n];
  double **phi_2 = new double*[n];
  double **phi_next_2 = new double*[n];

  
  for(int i = 0; i<n;i++){
    phi_inicial[i] = new double[n];
    phi[i] = new double[n];
    phi_next[i] = new double[n];

    phi_inicial_2[i] = new double[n];
    phi_2[i] = new double[n];
    phi_next_2[i] = new double[n];
  }
  
  input.open(file);

  for(int i = 0; i<n;i++){
    for(int j = 0; j<n;j++){
      double Pij;
      input >> Pij;
      
      phi_inicial[i][j] = Pij;
      phi[i][j] = Pij;

      phi_inicial_2[i][j] = Pij;
      phi_2[i][j] = Pij;
    }
  }


  for(int k = 0; k < N_t;k++){
 
    for(int i = 0; i<n;i++){
      for(int j = 0; j<n;j++){
	if(i == 0 || j == 0 || i == n-1 || j == n-1){
	  phi_next[i][j] = phi[i][j];
	}
	else{
	  phi_next[i][j] = q*(phi[i+1][j] + phi[i-1][j] + phi[i][j+1] + phi[i][j-1]) + 2*phi[i][j]*(1-2*q) - phi_inicial[i][j];
	}
      }
    }

    if(k%10 == 0){
	for(int i = 0; i<n;i++){
	  cout << phi_next[n/2][i] << ' ';
	}
	cout << endl;
      }
    

    for(int i = 1; i<n-1;i++){
      for(int j = 1; j<n-1;j++){
	phi_inicial[i][j] = phi[i][j]; 
	phi[i][j] = phi_next[i][j];
      }
    }
  }

  for(int i = 0; i<n;i++){
    for(int j = 0; j<n;j++){
      cout <<  phi_next[i][j] << ' ';
    }
    cout << endl;
    }

  /*cout << ' ' << endl;*/

  for(int k = 0; k < N_t; k++){
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){

        if(i != 0 && j != 0 && i != n-1 && j != n-1){
          phi_next_2[i][j] = q*(phi_2[i+1][j] + phi_2[i-1][j] + phi_2[i][j+1] + phi_2[i][j-1]) + 2*phi_2[i][j]*(1-2*q) - phi_inicial_2[i][j];
        
	  phi_next_2[i][0] = phi_next_2[i][1];                                                                                                  phi_next_2[i][n-1] = phi_next_2[i][n-2];
	  phi_next_2[0][j] =  phi_next_2[1][j];   
	  phi_next_2[n-1][j] = phi_next_2[n-2][j];
	}               

	phi_next_2[0][0] = phi_next_2[1][1];                                                                                          
        phi_next_2[n-1][0] = phi_next_2[n-2][1];                                                                                      
        phi_next_2[0][n-1] = phi_next_2[1][n-2];                                                                                      
        phi_next_2[n-1][n-1] = phi_next_2[n-2][n-2];                                                                                                   
      }
    }

    if(k%10 == 0){
      for(int i = 0; i<n;i++){
	cout << phi_next_2[n/2][i] << ' ';
      }
      cout << endl;
    }

    for(int i = 1; i<n-1;i++){
      for(int j = 1; j<n-1;j++){
        phi_inicial_2[i][j] = phi_2[i][j];
        phi_2[i][j] = phi_next_2[i][j];
      }
    }
  }

  for(int i = 0; i<n;i++){
    for(int j = 0; j<n;j++){
      cout <<  phi_next_2[i][j]<< ' ';
    }
    cout << endl;
  }




}
