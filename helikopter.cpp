////////////////////////////////////////////////////////////////////////
//Helikopter by Jerwin D. Dela Cruz
////////////////////////////////////////////////////////////////////////
//
// PRESS 'SPACEBAR' for the Helikopter Menu
// Then PRESS 'Y' if you want to continue flying the Helikopter
// Or PRESS 'N' if you want to stop flying the Helikopter
//
////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <fstream>

using namespace std;

//GLOBAL
bool enableMusic;
bool exitDone;

//VOID
void menuExit();
void hideCursor(bool condition);
void colorSet(int tint);
void getDesktopResolution(int& horizontal, int& vertical);
void displayHelikopter(bool helikopterFacingLeft, string tMotorTop, string tMotorBot);
void stopHelikopterMusic();
bool DoesFileExist(const std::string& name);
bool exitHandler(DWORD event);
string stopHelikopterFile();
string startHelikopterFile();
string downloadHelikopterMusicFile();

//MAIN
int main(){
	
	//VARIABLES
	int screenWidth = 0;
	int screenHeight = 0;
	int appWidthSize = 450;
	int appHeightSize = 150;
	
	int maxXPosition;
	int maxYPosition;
	
	system("cls");
	SetConsoleTitle("Helikopter");
	
	///////////////////
	//DO NOT CHANGE
	///////////////////
	exitDone = false;
	getDesktopResolution(screenWidth, screenHeight);

	maxXPosition = screenWidth - appWidthSize;
	maxYPosition = screenHeight - appHeightSize;

	HWND hwnd = GetConsoleWindow();
	
	if( hwnd != NULL ){
		MoveWindow(hwnd, 0, 0, appWidthSize, appHeightSize, TRUE); 
		ShowScrollBar(GetConsoleWindow(), SB_VERT, 0);
		SetConsoleCtrlHandler((PHANDLER_ROUTINE)(exitHandler), TRUE);
	}
	/////////////////// 
	
	
	
	//////////////////////////////////////
	/* Start, Hop, and FPS (You can set the numbers if you want) */
	//////////////////////////////////////
	 /* Helikopter Postion Holder (Adjust the xPosition and yPosition 
	 for the starting point of the Helikopter) */
	 int xPosition = 10;
	 int yPosition = 10;
	
	 /* Helikopter Hop Speed (Adjust the xSpeed and ySpeed 
	 for the Movement Speed) */
	 int xSpeed = 4;
	 int ySpeed = 4;
	
	 /* Helikopter Delay Speed (Adjust the FPS
	 for the imaginary frame rate speed of the Helikopter) */
	 int FPS = 60;
	 int xySpeed = 1000/FPS;
	//////////////////////////////////////
	
	//////////////////////////////////////
	/* Miscellaneous (You can set to true or false if you want) */
	//////////////////////////////////////
	 /*Enable Helikopter Bounce for the Helikopter 
	   to switch position when at the edge of the screen */
	 bool enableHelikopterBounce = true; 
	
	 /* HelikopterFacingLeft if set true it will start facing left */
     bool helikopterFacingLeft = true; 
     
	 //If Helikopter Bounce if set to false it will face right
	 bool  enableColorBounce = true;
	 
	 //Enable Music if set to true it will play music
	 enableMusic = true;
	 
	 /* You can set it to (none, avoidLeft, blinking)
		for the desktop icon behavior */
	 string iconCondition = "blinking";
	//////////////////////////////////////
	
	///////////////////
	//DO NOT CHANGE
	///////////////////
	int colorHolder = 15, colorSync;
	bool xBack = false, yBack = false, rtBlade = false, icoToggle = false;
	bool clrChangeA = true, clrChangeB = true, clrChangeC = true, clrChangeD = true;
	string tMotorTop;
	string tMotorBot;
	
		cout<<"Helikopter -> Programmer(Jerwin D. Dela Cruz)"<<endl;
	cout<<"Helikopter -> Resolution(";
	cout<<screenWidth<<" x "<<screenHeight<<") FPS("<<FPS<<")"<<endl;
	cout<<"Helikopter -> Start("<<xPosition<<","<<yPosition<<") -> Hop("<<xSpeed<<","<<ySpeed<<")"<<endl;
	//cout<<" | "<<maxXPosition<<" x "<<maxYPosition;
	///////////////////
	
	cout<<endl<<"Helikopter -> Loading";
	Sleep(700);
	cout<<".";
	Sleep(700);
	cout<<".";
	Sleep(700);
	cout<<".";
	Sleep(700);
	
	system("cls");
	MoveWindow(hwnd, 0, 0, appWidthSize, appHeightSize, TRUE); 
	
	
	//START Helikopter
	
	if(enableMusic == true){
		bool musicExecuteExist = DoesFileExist("playHelikopterMusic.vbs");
		bool musicFileExist = DoesFileExist("helikopter.wav");
		
		if(musicFileExist == true){
			if(musicExecuteExist == true){
				system("start playHelikopterMusic");
			}
			else{
				ofstream outfile;
				outfile.open ("startHelikopterMusic.vbs");
				outfile << startHelikopterFile();
				outfile.close();
				Sleep(1000);
				system("start startHelikopterMusic");
			}
		}
		else{
			ofstream outfile;
			outfile.open ("downloadHelikopterMusic.vbs");
			outfile << downloadHelikopterMusicFile();
			outfile.close();
			
			system("cls");
			cout<<"Helikopter -> Music Not Found"<<endl;
			Sleep(1000);
			
			system("start downloadHelikopterMusic");
			cout<<"Helikopter -> Downloading Music..."<<endl;
			Sleep(1000);
			bool musicDownloaderExist = DoesFileExist("downloadHelikopterMusic.vbs");
			if(musicDownloaderExist == true){
				remove("downloadHelikopterMusic.vbs");
			}
			Sleep(1000);
			cout<<"Helikopter -> Check if helikopter.wav is in"<<endl;
			cout<<"           -> your folder. Then relaunch this app!"<<endl;
			cout<<"           -> (Press any key to continue)";
			system("pause >nul");
			exit(0);
			
		}
		
		
		
	}
	
	while(true){
	
		hideCursor(true);
		ShowScrollBar(GetConsoleWindow(), SB_VERT, 0);
	
		if(xPosition < maxXPosition && xBack == false){
			xPosition += xSpeed;
		}
		else{
			if(xPosition > 0){
				xBack = true;
				xPosition -= xSpeed;
			}
			else{
				xBack = false;
			}
		}

		if(yPosition < maxYPosition && yBack == false){
			yBack = false;
			yPosition += ySpeed;
		}
		else{
			if(yPosition > 0){
				yBack = true;
				yPosition -= xSpeed;
			}
			else{
				yBack = false;
			}
		}
		
		system("cls");
		
		////////////////////////////////////////
		//COLOR
		////////////////////////////////////////
		string colorCon = "no color";
		
		if(xBack == 0 && yBack == 1){
			if(clrChangeA == true){
				colorCon = "change color 1";	
				clrChangeA = false;
				clrChangeB = true;
				clrChangeC = true;
				clrChangeD = true;
			}
		}
		if(xBack == 1 && yBack == 1){
			if(clrChangeB == true){
				colorCon = "change color 2";	
				clrChangeA = true;
				clrChangeB = false;
				clrChangeC = true;
				clrChangeD = true;
			}
		}
		if(xBack == 1 && yBack == 0){
			if(clrChangeC == true){
				colorCon = "change color 3";	
				clrChangeA = true;
				clrChangeB = true;
				clrChangeC = false;
				clrChangeD = true;
			}
		}
		if(xBack == 0 && yBack == 0){
			if(clrChangeD == true){
				colorCon = "change color 4";	
				clrChangeA = true;
				clrChangeB = true;
				clrChangeC = true;
				clrChangeD = false;
			}
		}
		
		//cout<<"Color: "<<colorCon<<" ";
		////////////////////////////////////////
		srand(time(0));
		if(enableColorBounce == true){
			if(colorCon == "no color"){
				colorSync = colorHolder;
			}
			else{
				colorSync = rand() % 15 + 1;
			}
		}
		else{
			colorSync = 15;
		}
		
		colorHolder = colorSync;  
		////////////////////////////////////////
		
		//ROTOR BLADE
		if(rtBlade == false){
			colorSet(colorSync);
			cout<<"        (<=:JERWIN=:LOL:"<<endl;
			rtBlade = true;
			tMotorTop = "L";
			tMotorBot = " ";
		}
		else{
			cout<<"                   :LOL:=JERWIN:=>)"<<endl;
			rtBlade = false;
			tMotorTop = " ";
			tMotorBot = "L";
		}

		//BODY
		if(enableHelikopterBounce == true){
			if(helikopterFacingLeft == true){
				if(xBack == false){
					displayHelikopter(true,tMotorTop,tMotorBot);
				}
				else{
					displayHelikopter(false,tMotorTop,tMotorBot);
				}
			}
			else{
				if(xBack == false){
					displayHelikopter(false,tMotorTop,tMotorBot);
				}
				else{
					displayHelikopter(true,tMotorTop,tMotorBot);
				}
			}
		}
		else{
			if(helikopterFacingLeft == true){
				displayHelikopter(true,tMotorTop,tMotorBot);
			}
			else{
				displayHelikopter(false,tMotorTop,tMotorBot);
			}
		}
		
		if(iconCondition == "avoidLeft"){
			if(xPosition < appWidthSize/2){
				HWND hProgman = FindWindowW (L"Progman", L"Program Manager");
				HWND hChild = GetWindow (hProgman, GW_CHILD);
				ShowWindow (hChild, SW_HIDE);
			}
			else{
				HWND hProgman = FindWindowW (L"Progman", L"Program Manager");
				HWND hChild = GetWindow (hProgman, GW_CHILD);
				ShowWindow (hChild, SW_SHOW);
			}
		}
		else if(iconCondition == "blinking"){
			if(icoToggle == false){
				HWND hProgman = FindWindowW (L"Progman", L"Program Manager");
				HWND hChild = GetWindow (hProgman, GW_CHILD);
				ShowWindow (hChild, SW_HIDE);
				icoToggle = true;
			}
			else{
				HWND hProgman = FindWindowW (L"Progman", L"Program Manager");
				HWND hChild = GetWindow (hProgman, GW_CHILD);
				ShowWindow (hChild, SW_SHOW);
				icoToggle = false;
			}
		}
		
		
	
		//cout<<"LEFT: "<<xBack<<" TOP: "<<yBack<<endl;
		//cout<<"LEFT: "<<xPosition<<" TOP: "<<yPosition<<endl;
		MoveWindow(hwnd, xPosition, yPosition, appWidthSize, appHeightSize, TRUE);
		
		//Enable if window is being resized always
		//ShowScrollBar(GetConsoleWindow(), SB_VERT, 0);
		
		
		//system("choice /d y /t 0 > nul");
		Sleep(xySpeed);
		
		 if(GetAsyncKeyState(VK_SPACE) != 0){
		 	menuExit();
		 }	
		 
	}
	//
	
}

void displayHelikopter(bool helikopterFacingLeft, string tMotorTop, string tMotorBot){	
	if(helikopterFacingLeft == true){
		cout<<"   "<<tMotorTop<<"            __ __|__"<<endl;
		cout<<" [LOL]________(::(   |@ "<<char(92)<<"__"<<endl;
		cout<<"   "<<tMotorBot<<"  "<<char(92)<<char(92)<<"-------"<<char(92)<<"___________)"<<endl;
		cout<<"	        __|___|___,    "<<endl;	
	}
	else{
		cout<<"                   __|__ __            "<<tMotorTop<<""<<endl;
		cout<<"                __/ @|  )::)_________[LOL] "<<endl;
		cout<<"               (___________/-------//  "<<tMotorBot<<"   "<<endl;
		cout<<"                ___|___|__,        "<<endl;
	}
}


//MENU EXIT
void menuExit(){
	HWND hwnd = GetConsoleWindow();
	MoveWindow(hwnd, 50, 50, 500, 80, TRUE); 
	
	HWND hProgman = FindWindowW (L"Progman", L"Program Manager");
	HWND hChild = GetWindow (hProgman, GW_CHILD);
	ShowWindow (hChild, SW_SHOW);
	
	stopHelikopterMusic();

	colorSet(15);
	char choice;
	do{	
	
		system("cls");
		cout<<"Do you want to continue flying the Helikopter? (Y/N): ";
		choice = getch();
		choice = tolower(choice);
		
		if(choice=='y'){
			main();
		}
		else if(choice=='n'){
			cout<<endl;
			exit(0);
		}
	
		}while(!(choice=='y'||choice=='n'));
		
}

void stopHelikopterMusic(){
	try{
		
		if(enableMusic == true){
			bool musicStopExist = DoesFileExist("stopHelikopterMusic.vbs");
			if(musicStopExist == true){
				system("start stopHelikopterMusic");
			}
			else{
				//SAVE NEW FILE CHECKER
				ofstream outfile;
				outfile.open ("stopHelikopterMusic.vbs");
				outfile << stopHelikopterFile();
				outfile.close();
				Sleep(1000);
				system("start stopHelikopterMusic");
			}
		}
	}
	catch(...){}
}

//GET DESKTOP RESOLUTION
void getDesktopResolution(int& horizontal, int& vertical)
{
   RECT desktop;
   // Get a handle to the desktop window
   const HWND hDesktop = GetDesktopWindow();
   // Get the size of screen to the variable desktop
   GetWindowRect(hDesktop, &desktop);
   // The top left corner will have coordinates (0,0)
   // and the bottom right corner will have coordinates
   // (horizontal, vertical)
   horizontal = desktop.right;
   vertical = desktop.bottom;
}

//COLOR SET
void colorSet(int tint){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), tint);
}

//HIDE CURSOR IN THE CONSOLE
void hideCursor(bool condition)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = (!(condition)); // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

string startHelikopterFile(){
	string text = "set WshShell = CreateObject(\"WScript.Shell\")\n\n";
			
		   text += "strCurDir = WshShell.CurrentDirectory\n";
		   text += "music = strCurDir & \"\\helikopter.wav\"\n\n";
			
		   text += "WshShell.Run \"wmplayer \"\"\" & music & \"\"\"\",0,True";
		   
	return text;
}

string stopHelikopterFile(){
	string text = "Dim objProcessSet, proname, process\n\n";
		   text += "On Error Resume Next\n\n";
		   
		   text += "Set objProcessSet = GetObject (\"winmgmts:{impersonationLevel=impersonate}\").InstancesOf(\"Win32_Process\")\n\n";
		   
		   text += "For Each process In objProcessSet\n";
		   text += "  proname = LCase(process.Name)\n\n";
		   
		   text += "  If proname = \"wmplayer.exe\" Then\n";
		   text += "    process.terminate()\n";
		   text += "    ShowSystemAlarm \"terminated wmplayer\"\n";
		   text += "  End If\n";
		   text += "Next\n";
		   text += "Set objProcessSet = Nothing";
		   
	return text;
}

string downloadHelikopterMusicFile(){
	string text = "dim xHttp: Set xHttp = createobject(\"Microsoft.XMLHTTP\")\n";
		   text += "dim bStrm: Set bStrm = createobject(\"Adodb.Stream\")\n";
		   text += "xHttp.Open \"GET\", \"https://jerwinkdc.github.io/helikopter/helikopter.wav\", False\n";
		   text += "xHttp.Send\n\n";
			
		   text += "set WshShell = CreateObject(\"WScript.Shell\")\n";
		   text += "strCurDir = WshShell.CurrentDirectory\n\n";
		   
		   text += "with bStrm\n";
		   text += "    .type = 1 '//binary\n";
		   text += "    .open\n";
		   text += "    .write xHttp.responseBody\n";
		   text += "    .savetofile strCurDir & \"\\helikopter.wav\", 2 '//overwrite\n";
		   text += "end with";
		   
	return text;
}

bool exitHandler(DWORD event)
{
    if (event == CTRL_CLOSE_EVENT) {
        exitDone = true;
		HWND hProgman = FindWindowW (L"Progman", L"Program Manager");
		HWND hChild = GetWindow (hProgman, GW_CHILD);
		ShowWindow (hChild, SW_SHOW);

        stopHelikopterMusic();
        return TRUE;
    }
    return FALSE;
}

//CHECK FILE
bool DoesFileExist (const std::string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }   
}

