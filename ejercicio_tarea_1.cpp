/*Ingrese nombre apellido edad y dni de 500 personas, reconocer y 
encontrar el ingreso de las personas con dos numeros de dni determinados
y en caso de encontrarlos mostrarlos en pantalla y ubicarlos en el vector

en caso de que una persona tenga la edad de 25 años y su numero de dni mayor a 30 millones
imprimir en pantalla datos y su ubicacion

contabilisar todas las personas que tengan entre 0 y 18 años y
un dni entre 40 y 60 millones

En caso de que se ingresen edades mayores a 100 años,
imprimir en pantalla fuera de rango
si se ingresan personas de 99 años y despues otra de 100 consecutivamente
el programa se reinicica y se sobreescriben todos los datos

Hacer un programa que haga lo siguente. 
Que el ingreso de datos empiece pidiendo un código de acceso (codigo:222333). 
Si el código es incorrecto no podrá dar inicio al programa. Si se ingresan 5 veces el código de manera errónea imprimir en pantalla 
"te quedan n veces para volver a ingresar el código" y vuelva a pedir el código. 
En el caso de que sean todos los ingresos erroneos no podrá arrancar y al finalizar se dará una impresión de pantalla " 
códigos erroneos programa finalizado".*/

#include<iostream>

using namespace std;

// Objeto

class user {
    private:
        string nombre;
        string apellido;
        int edad;
        int dni;
        int codigo_acceso = 222333;
        int codigo_acceso_cin;

    public:

        int contraseña() {
            cout<<"Ingrese el codigo de acceso: ";
            cin>>codigo_acceso_cin;
            fflush(stdin);
            if (codigo_acceso_cin == codigo_acceso) {
                return 1;
            }
            else {
                return 0;
            }
        }
        void ingreso_datos_user_part_1() {
            cout<<"Ingrese nombre: ";
            cin>>nombre;
            fflush(stdin);
            cout<<"Ingrese apellido: ";
            cin>>apellido;
            fflush(stdin);
        }
        void ingreso_datos_user_part_2() {
            cout<<"Ingrese edad: ";
            cin>>edad;
            fflush(stdin);
        }
        void ingreso_datos_user_part_3() {
            cout<<"Ingrese dni: ";
            cin>>dni;
            fflush(stdin);
            cout<<"Gracias por ingresar sus datos\n\n";
        }
        void mostrar_datos_user(int i) {
            cout<<"-------------------\n";
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"Apellido: "<<apellido<<endl;
            cout<<"Edad: "<<edad<<endl;
            cout<<"Dni: "<<dni<<endl;
            cout<<"Ubicacion vector: "<<i<<endl;
            cout<<"-------------------\n\n";
        }
        int dni_malicioso(int dni_malicioso_1, int dni_malicioso_2) {
            if ( (dni == dni_malicioso_1) || (dni == dni_malicioso_2) ) {
                return 1;
            }
            else {
                return 0;
            }
        }
        int dni_mayor_30millones_25_años() {
            if ( (edad == 25) && (dni > 30000000) ) {
                return 1;
            }
            else {
                return 0;
            }
        }
        int entre_0y18_con_dni_entre_40y60millones() {
            if ( ( (edad >= 0) && (edad <= 18) ) && ( (dni >= 40000000) && (dni <= 60000000) ) ) {
                return 1;
            }
            else {
                return 0;
            }
        }
        int mayor_100_años() {
            if (edad > 100) {
                return 1;
            }
            else {
                return 0;
            }
        }
        int edad_99_100(int exit) {
            if (exit = 0) {
                if (edad == 99) {
                    return 1;
                }
                else {
                    return 0;
                }
            }
            if (exit = 1) {
                if (edad == 100) {
                    return 2;
                }
                else {
                    return 0;
                }
            }
            return 0;
        }
    user ();
}usuarios[500];

// Constructor

user::user () {}

// Funciones

int ingreso_de_codigo() {
    int i = 0;
    do {
        if (i == 5) {
            cout<<"Te quedan 2 intentos para volver a ingresar el codigo\n";
        }
        else if (i == 7) {
            cout<<"Codigos erroneos, programa finalizado\n";
            return 0;
        }
        i++;
    }while ( usuarios[0].contraseña() == 0);
    cout<<"Codigo correcto"<<endl<<endl;
    return 1;
}

// Main

int main ()
{
    int i = 0, entre_0y18_con_dni_entre_40y60millones = 0, exit = 0;
    if (ingreso_de_codigo() == 0) {
        return 0;
    }
    while (i < 500) {
        usuarios[i].ingreso_datos_user_part_1();

        do {
            usuarios[i].ingreso_datos_user_part_2();
            if (usuarios[i].edad_99_100(exit) == 1) {
                exit = 1;
            }
            else if (usuarios[i].edad_99_100(exit) == 2) {
                break;
            }
            else {
                exit = 0;
            }
            if (usuarios[i].mayor_100_años() == 1) {
                cout<<"fuera de rango\n";
            }
        } while ( usuarios[i].mayor_100_años() );
        if (usuarios[i].edad_99_100(exit) == 2) {
            i = 0;
            exit = 0;
            cout<<"\nPrograma reiniciado...\n";
            if (ingreso_de_codigo() == 0) {
                return 0;
            }
            continue;
        }
        usuarios[i].ingreso_datos_user_part_3();
        i++;
    }
    i = 0;
    cout<<"Personas con dni malicioso\n";
    while (i < 500) {
        if ( usuarios[i].dni_malicioso(44531831,21122833) == 1) {
            usuarios[i].mostrar_datos_user(i);
        }
        i++;
    }
    i = 0;
    cout<<"Personas con 25 años con dni mayor a 30 millones\n";
    while (i < 500) {
        if ( usuarios[i].dni_mayor_30millones_25_años() == 1) {
            usuarios[i].mostrar_datos_user(i);
        }
        i++;
    }
    i = 0;
    cout<<"Personas entre 0 y 18 años con dni entre 40 y 60 millones: ";
    while (i < 500) {
        if ( usuarios[i].entre_0y18_con_dni_entre_40y60millones() == 1) {
            entre_0y18_con_dni_entre_40y60millones++;
        }
        i++;
    }
    cout<<entre_0y18_con_dni_entre_40y60millones<<endl<<endl;
    return 0;
}