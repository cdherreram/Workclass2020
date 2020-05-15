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
  double radio;
  double r[3],v[3],f[3];
};

//simulation conditions
const int N = 1;
const double G = 9.81;
const double DT = 0.01;
const double K = 123.9;
const double B = 0.1;
const double lx = 3.2;
const double lxizq = -1.5;

//helper function
void initial_conditions(std::vector<body> & bodies);
void timestep(std::vector<body> & bodies, double dt);
void star_timeintegration(std::vector<body> & bodies, double dt);
void compute_force(std::vector<body> & bodies);
void print_system(std::vector<body> & bodies,double time);
void print_csv(const std::vector<body> & bodies, int step);

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

  //preprocessing
  initial_conditions(bodies);
  compute_force(bodies);
  star_timeintegration(bodies,DT);

  //processsing
  for ( int step = 0; step < 1000; ++step){
    double tstep =step*DT;
    std::cout << tstep << "  " 
              << bodies[0].r[0] << "  "
              << bodies[0].r[1] << "  "
              << bodies[0].r[2] << "  "
              << bodies[0].v[0] << "  "
              << bodies[0].v[1] << "  "
              << bodies[0].v[2] << "  "
              << std::endl;
    timestep(bodies,DT);
    compute_force(bodies);
    //    print_csv(bodies,step);
  }
  
  print_system(bodies,0);
  
  return 0;
}

void initial_conditions(std::vector<body> & bodies){
  bodies[0].masa = 1.23;
  bodies[0].radio = 0.16;
  bodies[0].r[2] = 7.86;
  bodies[0].v[0] = 0.87;
  bodies[0].v[2] = 1.32;
}

void compute_force(std::vector<body> & bodies){
  //reset forces
  for( auto & cuerpo: bodies){
    cuerpo.f[0] = cuerpo.f[1] = cuerpo.f[2] = 0.0;
  }

  for( auto & cuerpo: bodies){
    //add gravity
    cuerpo.f[2] -= cuerpo.masa * G;
    //Fuerza de rebote con el suelo
    double delta = cuerpo.radio - cuerpo.r[2];
    if ( delta > 0){
      cuerpo.f[2] += K*delta;
      cuerpo.f[2] -= B*cuerpo.masa*cuerpo.v[2];
    }
    //Fuerza horizontal contra pared de la derecha
    delta = cuerpo.r[0] + cuerpo.radio -lx;
    if (delta > 0){
     cuerpo.f[0] += -K*delta - B*cuerpo.masa*cuerpo.v[0];
    }
    //Fuerza horizontal contra pared de la izquierda
    delta = lxizq -(cuerpo.r[0] - cuerpo.radio);
    if (delta > 0){
     cuerpo.f[0] += +K*delta - B*cuerpo.masa*cuerpo.v[0];
    }
  }
}

void star_timeintegration(std::vector<body> & bodies, double dt){
  for (auto & cuerpo: bodies){
    cuerpo.v[0] = cuerpo.v[0]-dt*cuerpo.f[0]/(2*cuerpo.masa);
    cuerpo.v[1] = cuerpo.v[1]-dt*cuerpo.f[1]/(2*cuerpo.masa);
    cuerpo.v[2] = cuerpo.v[2]-dt*cuerpo.f[2]/(2*cuerpo.masa);
  }
}

void timestep(std::vector<body> & bodies, double dt){
  for( auto & cuerpo:bodies){
    for ( int ii = 0; ii <= 2; ii++){
      cuerpo.v[ii] += cuerpo.f[ii]*dt/cuerpo.masa;
      cuerpo.r[ii] += cuerpo.v[ii]*dt;
    }
  }
}

void print_system(std::vector<body> & bodies,double time){
  std::ofstream fout("datos.txt",std::fstream::out);
  fout.precision(5); fout.setf(std::ios::scientific);

  for ( const auto & cuerpo : bodies){
    fout << cuerpo.r[0] << "  " << cuerpo.r[1] << "  " << cuerpo.r[2] << "\t"
         << cuerpo.v[0] << "  " << cuerpo.v[1] << "  " << cuerpo.v[2] << "\t"
         << cuerpo.f[0] << "  " << cuerpo.f[1] << "  " << cuerpo.f[2] << "\t"
	 << cuerpo.masa << "\n";
  }
}

void print_csv(const std::vector<body> & bodies, int step){
  std::string fname = "data-" +std::to_string(step) + ".csv";
  std::ofstream fout(fname,std::ofstream::out);
  fout.precision(15); fout.setf(std::ios::scientific);
  
 for ( const auto & cuerpo : bodies){
   fout << cuerpo.r[0] << "," << cuerpo.r[1] << "  " << cuerpo.r[2] << cuerpo.radio<< "\n";
  }
 fout.close();
}
