#include <bits/stdc++.h>
#include <windows.h>
#include <dirent.h>
using namespace std;
int i = -1;
string globalpath;


string InitPath() {
    char buffer[MAX_PATH];
    GetModuleFileName( NULL, buffer, MAX_PATH );
    string::size_type pos = string( buffer ).find_last_of( "\\/" );
    return string( buffer ).substr( 0, pos);
}


void reccursiveDir(string currentDirPath)
{
struct dirent * fileProprety;
DWORD ftyp;
DIR * newDir;
string newFullPath;
if ((newDir = opendir(currentDirPath.c_str())) == NULL) return;
while (fileProprety = readdir(newDir))
{
    if (fileProprety->d_name[0] == '.')
        continue;
    newFullPath = currentDirPath + "\\" + fileProprety->d_name;
    ftyp =  GetFileAttributesA(newFullPath.c_str());
    if (ftyp == INVALID_FILE_ATTRIBUTES)
        return;
    if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
        reccursiveDir(newFullPath);
    if (currentDirPath == globalpath)
        continue;
    int foundedDot = newFullPath.find_last_of(".");
    if (!foundedDot || foundedDot > newFullPath.size())
        continue;
    if (newFullPath.substr(foundedDot) == ".docx")
    {
        int found = string(fileProprety->d_name).find_last_of(".");
        string filname =  string(fileProprety->d_name).substr(0, found)
                            + "GrabbedFile" + string(fileProprety->d_name).substr(found);
        CopyFile(newFullPath.c_str(), filname.c_str(), TRUE);
    }
}

}

/*
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
*/

int main() {
cout << "working in " << InitPath() << "\n";
   string path = InitPath();
    globalpath = path;
    reccursiveDir(path);

    system("PAUSE");
}
