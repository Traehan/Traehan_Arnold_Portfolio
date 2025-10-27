#include <fcntl.h>
#include <unistd.h>

int main (int arg, char *argv[]){

    int fin, fout;
    int nbytes;
    char buffer[1024];

    fin = open(argv[1], O_RDONLY);
    if( fin ==-1) {
        write(2, "Error Opening file \n", 19);
        return -1;
    }

    fout = open(argv[2], O_WRONLY, 0644);
    if (fout == -1) {
        write(2, "Error Opening file \n", 20);
        return -1;
    }

    while ((nbytes = read(fin, buffer, 1024)) !=0){
        write(fout, buffer, nbytes);
    }

    close(fin);
    close(fout);

    return 0;
   
}

