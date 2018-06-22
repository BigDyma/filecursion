#include <bits/stdc++.h>
#include <windows.h>
#include <dirent.h>
using namespace std;
/*

Get exe full path

string InitPath() {
    char buffer[MAX_PATH];
    GetModuleFileName( NULL, buffer, MAX_PATH );
    string::size_type pos = string( buffer ).find_last_of( "\\/" );
    return string( buffer ).substr( 0, pos);
}*/
int ls(string path)
{
 DIR * currentDir;
 string currentDirData;
 struct dirent * filesProprietes;
 if (currentDir = opendir(path.c_str()))
    {
        while (filesProprietes = readdir(currentDir))
        {
            currentDirData += filesProprietes->d_name ;
            currentDirData += "\n";

        }
    }
    cout << currentDirData << endl;
    return 0;

}

int main() {
   // cout << "my directory is " << InitPath() << "\n";
   string path ;//= InitPath();
   path = ".";
    ls(path);

    system("PAUSE");
}
