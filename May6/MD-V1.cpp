#include <iostream>
#include<vector>
#include <fstream>

/*Este programa simula un cuerpo que cae bajo accion de la gravedad y en el futuro va a rebotar contra el suelo y contra otros cuerpos
 */


/*
  Cuerpo:
  - masa (densidad)
  - (forma: esfera)
  - r[3], v[3], F[3]
*/
//Cuerpo 
struct body{
  double masa;
  double r[3],v[3],f[3];
};

//simulation conditions
const int N = 1;
const double G = 9.81;
const double DT = 0.1;

//helper function
void initial_conditions(std::vector<body> & bodies);
void timestep(std::vector<body> & bodies, double dt);
void star_timeintegration(std::vector<body> & bodies, double dt);
void compute_force(std::vector<body> & bodies);
void print_system(std::vector<body> & bodies,double time);

/*
  Condiciones externas
  - Gravedad

  Funciones
  - initial_conditions

  - timestep (nueva posicion y nueva velocidad)
  - star_timeintegration()
  - compute_force()
    - (implementar la fuerza de Hertz)
    - (Fuerza del rebote)
    - (Fuerza de gravedad)
    - (Amortiguamiento)
    - (Fuerza de friccion, si es que se considera)
  - print_system

  - Visualization

 */

int main( void)
{
  std::vector<body> bodies(N);

  initial_conditions(bodies);
  print_system(bodies,0);
  
  return 0;
}

void initial_conditions(std::vector<body> & bodies){
  bodies[0].masa = 1.23;
  bodies[0].r[2] = 7.86;
  bodies[0].v[2] = 1.32;
}

void print_system(std::vector<body> & bodies,double time){
  std::ofstream fout("datos.txt",std::fstream::out);
  fout.precision(5); fout.setf(std::ios::scientific);

  for ( const auto & cuerpo : bodies){
    fout << cuerpo.r[0] << "  " << cuerpo.r[1] << "  " << cuerpo.r[2] << "\n"
         << cuerpo.v[0] << "  " << cuerpo.v[1] << "  " << cuerpo.v[2] << "\n"
         << cuerpo.f[0] << "  " << cuerpo.f[1] << "  " << cuerpo.f[2] << "\n"
	 << cuerpo.masa << "\n";
  }
}

