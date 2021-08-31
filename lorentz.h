using namespace std;

#include <math.h>
#include <cmath>

#define pi 3.1415
#define GET_VARIABLE_NAME(Variable) (#Variable)

const int dimension_del_espacio=4;

class mandelstan_variables 
{
	public:
		//declaramos las variables publocas para poder emplearlas en funciones ajenas a la clase
		double s;
		double t;
		double u;
		//constructor base
		mandelstan_variables() {}

		//constructor parametrizado
		mandelstan_variables(double a, double b, double c) : s(a), t(b), u(c) {}
};

static mandelstan_variables mandelstan(0,0,0);

class trivector 
{
	public:
		//declaramos las variables publocas para poder emplearlas en funciones ajenas a la clase
		double x;
		double y;
		double z;

		//constructor base
		trivector() {}

		//constructor parametrizado
		trivector(double a, double b, double c) : x(a), y(b), z(c) {}

		//funciones declaradas dentro
		double mod()
		{
			double resultado;
			resultado=pow((x*x + y*y + z*z),0.5);
			return resultado;
		}
};

class vector 
{
	public:
		//declaramos las variables publocas para poder emplearlas en funciones ajenas a la clase
		double t;
		double x;
		double y;
		double z;

		//constructor base
		vector() {}

		//constructor parametrizado
		vector(double time, double a, double b, double c) : t(time), x(a), y(b), z(c) {}

		//funciones declaradas dentro
		double mod()
		{
			double resultado;
			resultado=pow(t*t - (x*x + y*y + z*z),0.5);
			return resultado;
		}

		double trimod()
		{
			double resultado;
			resultado=pow((x*x + y*y + z*z),0.5);
			return resultado;
		}
		double masa()
		{
			double resultado=mod();
			return resultado;
		}
		double energia()
		{
			double resultado = pow(pow(trimod(),2)+pow(masa(),2),0.5);
			return resultado;
		}
		double velocity()
		{
			double resultado=trimod()/energia();
			return resultado;
		}
		
};

class lorentz_vector
{
	public:
		vector parte_vector;
		string indice_lorentz;
		
		//constructor base
		lorentz_vector() {}

		//constructor parametrizado
		lorentz_vector(vector parte_vector_0, string indice_lorentz_0) : parte_vector(parte_vector_0), indice_lorentz(indice_lorentz_0) {}

		//funciones declaradas internamente

};

class matriz 
{
	public:
		//declaramos las variables publocas para poder emplearlas en funciones ajenas a la clase
		vector t;
		vector x;
		vector y;
		vector z;

		//constructor base
		matriz() {}

		//constructor parametrizado
		matriz(vector time, vector a, vector b, vector c) : t(time), x(a), y(b), z(c) {}
		
};


//sobrecarga de operadores

ostream& operator<<(ostream& os, const vector& v)  
{  
	os << "(" << v.t << ", " << v.x << ", " << v.y << ", " << v.z << ")" << endl; 
	return os;  
}  

ostream& operator<<(ostream& os, const lorentz_vector& v)  
{  
	os << "(" << v.parte_vector.t << ", " << v.parte_vector.x << ", " << v.parte_vector.y << ", " << v.parte_vector.z << ", " << v.indice_lorentz << ")" << endl; 
	return os;  
}  

ostream& operator<<(ostream& os, const matriz& M)  
{  
	
	os << "(" << M.t.t << ", " << M.t.x << ", " << M.t.y << ", " << M.t.z << ")" << endl;
	os << "(" << M.x.t << ", " << M.x.x << ", " << M.x.y << ", " << M.x.z << ")" << endl;
	os << "(" << M.y.t << ", " << M.y.x << ", " << M.y.y << ", " << M.y.z << ")" << endl;
	os << "(" << M.z.t << ", " << M.z.x << ", " << M.z.y << ", " << M.z.z << ")" << endl;
	return os;  
}  

vector operator+(vector v1, vector v2)
{
	vector resultado;
	resultado.t=v1.t + v2.t;
	resultado.x=v1.x + v2.x;
	resultado.y=v1.y + v2.y;
	resultado.z=v1.z + v2.z;
	return resultado;
}

vector operator-(vector v1, vector v2)
{
	vector resultado;
	resultado.t=v1.t - v2.t;
	resultado.x=v1.x - v2.x;
	resultado.y=v1.y - v2.y;
	resultado.z=v1.z - v2.z;
	return resultado;
}

vector operator*(double a, vector v)
{
	vector resultado;
	resultado.t=v.t*a;
	resultado.x=v.x*a;
	resultado.y=v.y*a;
	resultado.z=v.z*a;
	return resultado;
}
vector operator*(vector v,double a)
{
	vector resultado;
	resultado.t=v.t*a;
	resultado.x=v.x*a;
	resultado.y=v.y*a;
	resultado.z=v.z*a;
	return resultado;
}


double operator*(vector v1, vector v2)
{
	double resultado;
	resultado=v1.t*v2.t - (v1.x*v2.x + v1.y*v2.y + v1.z*v2.z);
	return resultado;
}

vector operator*(matriz M, vector v)
{
	vector resultado;
	resultado.t=v*M.t;
	resultado.x=v*M.x;
	resultado.y=v*M.y;
	resultado.z=v*M.z;
	return resultado;
}

matriz operator*(vector v,matriz M)
{
	matriz resultado;
	resultado.t=v.t*M.t;
	resultado.x=v.x*M.x;
	resultado.y=v.y*M.y;
	resultado.z=v.z*M.z;
	return resultado;
}

matriz operator*(matriz M1, matriz M2)
{
	matriz resultado;
	resultado.t.t=M1.t.t*M2.t.t + M1.t.x*M2.x.t + M1.t.y*M2.y.t + M1.t.z*M2.z.t;
	resultado.t.x=M1.t.t*M2.t.x + M1.t.x*M2.x.x + M1.t.y*M2.y.x + M1.t.z*M2.z.x;
	resultado.t.y=M1.t.t*M2.t.y + M1.t.x*M2.x.y + M1.t.y*M2.y.y + M1.t.z*M2.z.y;
	resultado.t.z=M1.t.t*M2.t.z + M1.t.x*M2.x.z + M1.t.y*M2.y.z + M1.t.z*M2.z.z;
	
	resultado.x.t=M1.x.t*M2.t.t + M1.x.x*M2.x.t + M1.x.y*M2.y.t + M1.x.z*M2.z.t;
	resultado.x.x=M1.x.t*M2.t.x + M1.x.x*M2.x.x + M1.x.y*M2.y.x + M1.x.z*M2.z.x;
	resultado.x.y=M1.x.t*M2.t.y + M1.x.x*M2.x.y + M1.x.y*M2.y.y + M1.x.z*M2.z.y;
	resultado.x.z=M1.x.t*M2.t.z + M1.x.x*M2.x.z + M1.x.y*M2.y.z + M1.x.z*M2.z.z;
	
	resultado.y.t=M1.y.t*M2.t.t + M1.y.x*M2.x.t + M1.y.y*M2.y.t + M1.y.z*M2.z.t;
	resultado.y.x=M1.y.t*M2.t.x + M1.y.x*M2.x.x + M1.y.y*M2.y.x + M1.y.z*M2.z.x;
	resultado.y.y=M1.y.t*M2.t.y + M1.y.x*M2.x.y + M1.y.y*M2.y.y + M1.y.z*M2.z.y;
	resultado.y.z=M1.y.t*M2.t.z + M1.y.x*M2.x.z + M1.y.y*M2.y.z + M1.y.z*M2.z.z;
	
	resultado.z.t=M1.t.t*M2.t.t + M1.z.x*M2.x.t + M1.z.y*M2.y.t + M1.z.z*M2.z.t;
	resultado.z.x=M1.z.t*M2.t.x + M1.z.x*M2.x.x + M1.z.y*M2.y.x + M1.z.z*M2.z.x;
	resultado.z.y=M1.z.t*M2.t.y + M1.z.x*M2.x.y + M1.z.y*M2.y.y + M1.z.z*M2.z.y;
	resultado.z.z=M1.z.t*M2.t.z + M1.z.x*M2.x.z + M1.z.y*M2.y.z + M1.z.z*M2.z.z;
	return resultado;
}

matriz operator*(double a,matriz M)
{
	matriz resultado;
	resultado.t=a*M.t;
	resultado.x=a*M.x;
	resultado.y=a*M.y;
	resultado.z=a*M.z;
	return resultado;
}

matriz operator*(matriz M,double a)
{
	matriz resultado;
	resultado.t=a*M.t;
	resultado.x=a*M.x;
	resultado.y=a*M.y;
	resultado.z=a*M.z;
	return resultado;
}

void mandelstan_variables(vector p1,vector p2,vector p3,vector p4)
{
	mandelstan.s=(p1+p2)*(p1+p2);
	mandelstan.t=(p1-p3)*(p1-p3);
	mandelstan.u=(p1-p4)*(p1-p4);
}

double velocidad_relativa(vector p1, vector p2)
{
	return p1.velocity() + p2.velocity();
}

//contraccion de 2 vectores_lorentz

double operator*(lorentz_vector p1, lorentz_vector p2)
{
	if(p1.indice_lorentz==p2.indice_lorentz){return p1.parte_vector*p2.parte_vector;}
}

double contract(lorentz_vector p[],int numero)
{

	int repeticiones=0;
	for(int i=0 ; i<numero ; i++)
	{
		for(int j=0 ; j<numero ; j++)
		{
			if(p[i].indice_lorentz==p[j].indice_lorentz and i!=j){repeticiones++;}
		}
		if (repeticiones!=1)
		{
			cout << "espacio Lorentz inconsistente" << endl;
			return 0;
		}
		repeticiones=0;
	}

	double resultado=1;
	bool usados[numero];
	for(int i=0 ; i<numero ; i++){usados[i]=false;}
	for(int i=0 ; i<numero ; i++)
	{
		if(usados[i]==true){continue;}
		for(int j=0 ; j<numero ; j++)
		{
			if(usados[j]==1){continue;}
			if(p[i].indice_lorentz==p[j].indice_lorentz and i!=j)
			{
				resultado = resultado*(p[i]*p[j]); 
				usados[j]=true;
				usados[i]=true;
				break;
			}
		}
	}
	return resultado;
}
