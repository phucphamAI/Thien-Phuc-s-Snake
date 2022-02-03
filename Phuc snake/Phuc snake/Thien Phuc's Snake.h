#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <thread>
#include <mutex>
#include "mylib.h"
#define MAX 100
using namespace std;
mutex m;
// ============== Khởi tạo các giá trị ===========
// ============= Di chuyển  ===========
char c;
int check = 2;//0: đi xuống
				//1: đi lên
				//2: qua phải
				//3: qua trái
// ========= Rắn mẹ =============
int me_x[MAX];
int me_y[MAX];
int me_hp = 2;
// ========= Rắn con ============
int con_x[MAX];
int con_y[MAX];
bool tien_hoa = false;
// ========== Nhện ==========
int nhen_x = 20;
int nhen_y = 15;
int hp_nhen = 6;
// ========= Sâu ==========
int hp_sau = 8;
int sau_x = 35;
int sau_y = 15;
// ========= Quả ===========
int qua_x = -1;
int qua_y = -1;
// ========= Hoa ========
int hoa_x = -1;
int hoa_y = -1;
// ========= Vàng =======
int vang_x[MAX];
int vang_y[MAX];
int sl_vang = 0;
// ========= Chuột ======
int x_chuot = 84;
int y_chuot = 2;
// ========= Rắn cổ đại ========
int x_ran_co_dai = 20;
int y_ran_co_dai = 27;
bool ran_co_dai = false;
// ========= Các hàm số lượng ========
int hoa = 0;
int vang = 0;
bool gem = false;
bool game_over = false;
int cnt = 0;
bool thoat = false;
int lua_chon = 0;

void reset();

// ====================== Intro =========================
void ve();
void bang_thoat();
void bang_thua();
void bang_menu();
// ==================  Các hàm tạo - vẽ nhân vật  ========================
// ============= Tường,khung điểm =================
void ve_khung_diem(int hp, int gold, int flower, bool gem);
bool ban_trung_qua(int x, int y);
bool ban_trung_hoa(int x, int y);
void ve_tuong();
void ve_chuot();
void xoa_chuot_them_hoa();
// ========= Rắn mẹ =============
void tao_ran_me();
void ve_ran_me();
void me_di_chuyen(int x, int y);
bool ban_trung_vang(int x, int y);
// ========= Rắn con ============
void tao_ran_con();
void ve_ran_con(bool tien_hoa);
void ran_de_quai();
void ve_vang();
void tia_lua(int choose);
void xoa_hoa();
void skill_ran_con();
void con_di_chuyen(int x, int y);

// ========= Sâu, vàng =========
bool ban_trung_sau(int x, int y);
bool sau_an_hoa();
bool ve_sau();
void sau_di_chuyen();
// ========= Quả ===========
void tao_qua();
bool kt_ran_de_qua();
void ve_qua();
bool kt_ran_an_qua();
// ========= Hoa ========
void tao_hoa();
bool kt_ran_de_hoa();
bool kt_ran_an_vang();
void ve_hoa();
bool kt_ran_an_hoa();
//======================= Nhện =================
bool ve_nhen();
void nhen_di_chuyen();
bool ban_trung_nhen(int x, int y);
//================= Cổng 2 gold ================
void ve_cong();
// ==================== Hàm play ====================
void play();
void chay_game();

// ==================== Nội dung hàm ========================
void chay_game()
{
	thread first(play);
	thread second(nhen_di_chuyen);
	thread third(sau_di_chuyen);
	thread forth(skill_ran_con);
	first.join();
	second.join();
	third.join();
	forth.join();
}

//***********************   Nội dung hàm *****************************************
void reset()
{

	check = 2;//0: đi xuống
					//1: đi lên
					//2: qua phải
					//3: qua trái
	// ========= Rắn mẹ =============
	me_hp = 2;
	// ========= Rắn con ============
	tien_hoa = false;
	// ========== Nhện ==========
	nhen_x = 20;
	nhen_y = 15;
	hp_nhen = 6;
	// ========= Sâu ==========
	hp_sau = 8;
	sau_x = 35;
	sau_y = 15;
	// ========= Quả ===========
	qua_x = -1;
	qua_y = -1;
	// ========= Hoa ========
	hoa_x = -1;
	hoa_y = -1;
	// ========= Vàng =======
	sl_vang = 0;
	// ========= Chuột ======
	x_chuot = 84;
	y_chuot = 2;
	// ========= Rắn cổ đại ========
	x_ran_co_dai = 20;
	y_ran_co_dai = 27;
	ran_co_dai = false;
	// ========= Các hàm số lượng ========
	hoa = 0;
	vang = 0;
	gem = false;
	game_over = false;
	cnt = 0;
	thoat = false;
	lua_chon = 0;
}

// ====================== Intro =========================
void ve()
{
	int x_new = 35;
	int x_chu = 0;
	int x = 65;
	int y = 10, y_dif = 0;

	//================ Logo Becodeching ================
	SetColor(7);
	gotoXY(x_new + 26, y_dif++);
	cout << "-/:-`";
	gotoXY(x_new + 15, y_dif++);
	cout << "`:/++/-     `:+++++-";
	gotoXY(x_new + 13, y_dif++);
	cout << "`:oooooooo - -///++++/`";
	gotoXY(x_new + 12, y_dif++);
	cout << ".osooooooooo+-   `/////////.";
	gotoXY(x_new + 11, y_dif++);
	cout << "/oosooooooooooo+.  `:////////-";
	gotoXY(x_new + 10, y_dif++);
	cout << "`+ssssooo+:-:+ooooo:`  .:///////:`";
	gotoXY(x_new + 9, y_dif++);
	cout << "-osssssso-     ./ooo++-  `:://////:`";
	gotoXY(x_new + 8, y_dif++);
	cout << ":ssssssso.  .:::.``:oo++/`  -::::///:";
	gotoXY(x_new + 7, y_dif++);
	cout << "/ssssssso` `:///:::- `/+++/-  .::::::::. ";
	gotoXY(x_new + 6, y_dif++);
	cout << "`+sssssss+` `////`   `-. ./++/:` `::::::::.";
	gotoXY(x_new + 5, y_dif++);
	cout << "`osssssss+` .////` `    `-` -+//:` `-:::::::";
	gotoXY(x_new + 4, y_dif++);
	cout << "`osssssss+` `////. .       `` `///:`  -:::::::`";
	gotoXY(x_new + 3, y_dif++);
	cout << "`oyssssss+` `////- .`           .///.  `::::::::`";
	gotoXY(x_new + 2, y_dif++);
	cout << "+yyssssso`  ://+/ `-         `.-//:.   .::::::::.";
	gotoXY(x_new + 1, y_dif++);
	cout << "`yyysssso`  -+++/` ..   ``...-..` ``..-::::::::::`";
	gotoXY(x_new + 1, y_dif++);
	cout << "/osso+/`  .++++: `--``````....---::::::::::::-.`";
	gotoXY(x_new + 10, y_dif++);
	cout << "`/++++.  `.--------------------...``";
	gotoXY(x_new + 10, y_dif++);
	cout << "`/++++. `.--------------------...``";
	gotoXY(x_new + 10, y_dif++);
	cout << ":+++++`   ```......``````";
	gotoXY(x_new + 10, y_dif++);
	cout << ".++++++/-.``````````.....--:::::";
	gotoXY(x_new + 9, y_dif++);
	cout << ":+++++++++++oooooooooooooooooosss/";
	gotoXY(x_new + 9, y_dif++);
	cout << "-++++++++oooooooooooooooooossssssy/";
	gotoXY(x_new + 9, y_dif++);
	cout << "./++++oooooooooooooooooossssssyys:";
	gotoXY(x_new + 11, y_dif++);
	cout << "`...----:::::::::::::::--..";
	Sleep(2000);
	int y_k = y_dif;
	SetColor(13);
	for (int i = 0; i <= 15; i++)
	{
		y_dif = y_k;
		gotoXY(x_chu + 1 + i, y_dif++);
		cout << "_______                                       __                      __        __";
		gotoXY(x_chu + i, y_dif++);
		cout << "/       \\                                     /  |                    /  |      /  |";
		gotoXY(x_chu + i, y_dif++);
		cout << "$$$$$$$  |  ______    _______   ______    ____$$ |  ______    _______ $$ |____  $$/  _______    ______";
		gotoXY(x_chu + i, y_dif++);
		cout << "$$ |__$$ | /      \\  /       | /      \\  /    $$ | /      \\  /       |$$      \\ /  |/       \\  /      \\";
		gotoXY(x_chu + i, y_dif++);
		cout << "$$    $$< /$$$$$$  |/$$$$$$$/ /$$$$$$  |/$$$$$$$ |/$$$$$$  |/$$$$$$$/ $$$$$$$  |$$ |$$$$$$$  |/$$$$$$  |";
		gotoXY(x_chu + i, y_dif++);
		cout << "$$$$$$$  |$$    $$ |$$ |      $$ |  $$ |$$ |  $$ |$$    $$ |$$ |      $$ |  $$ |$$ |$$ |  $$ |$$ |  $$ |";
		gotoXY(x_chu + i, y_dif++);
		cout << "$$ |__$$ |$$$$$$$$/ $$ \\_____ $$ \\__$$ |$$ \\__$$ |$$$$$$$$/ $$ \\_____ $$ |  $$ |$$ |$$ |  $$ |$$ \\__$$ |";
		gotoXY(x_chu + i, y_dif++);
		cout << "$$    $$/ $$       |$$       |$$    $$/ $$    $$ |$$       |$$       |$$ |  $$ |$$ |$$ |  $$ |$$    $$ |";
		gotoXY(x_chu + i, y_dif++);
		cout << "$$$$$$$/   $$$$$$$/  $$$$$$$/  $$$$$$/   $$$$$$$/  $$$$$$$/  $$$$$$$/ $$/   $$/ $$/ $$/   $$/  $$$$$$$ |";
		gotoXY(x_chu + 95 + i, y_dif++);
		cout << "/  \__$$ |";
		gotoXY(x_chu + 95 + i, y_dif++);
		cout << "$$    $$/";
		gotoXY(x_chu + 96 + i, y_dif++);
		cout << "$$$$$$/";
		Sleep(270);
	}
	Sleep(2000);
	system("cls");

}
void bang_thoat()
{
	int x_new = 35;
	int x_chu = 0;
	int x = 65;
	int y = 10, y_dif = 0;
	// ==========================================================================
	SetColor(6);
	gotoXY(x + 25, y++);
	cout << ".-.";
	gotoXY(x + 25, y++);
	cout << "'-'";
	gotoXY(x + 24, y++);
	cout << "//";
	gotoXY(x + 23, y++);
	cout << "_..---._/|";
	gotoXY(x + 15, y++);
	cout << ".' .\"     '-.";
	gotoXY(x + 13, y++);
	cout << "/__/          \\      *";
	gotoXY(x + 11, y++);
	cout << "====_____     __|     :";
	gotoXY(x + 10, y++);
	cout << "/#   #\"\"\" |   /()\    :    ..*";
	gotoXY(x + 10, y++);
	cout << "|#   #    |   \\__/    : .''";
	gotoXY(x + 10, y++);
	cout << "\\#___#____|      /   :::.. .";
	gotoXY(x + 9, y++);
	cout << "\\______________|_...ä_: .. '*";
	gotoXY(x + 2, y++);
	cout << "()       // /\\||||)))))))      '   . .";
	gotoXY(x + 1, y++);
	cout << ".( \\_     \\\\_\\//   _-'.'/        |   * ..";
	gotoXY(x, y++);
	cout << "( )  |^|^|^|ooo/  _#\\.//\"\"\"_ | . . .";
	gotoXY(x, y++);
	cout << "(_)_.'v|v|v|     / \#  \\_ / '_  _'    . .";
	gotoXY(x + 11, y++);
	cout << "| _ _/_/     /'./_-|\"         . .";
	gotoXY(x + 11, y++);
	cout << "/#_#__\"\"\" - ._ / #  \\__)       .  .";
	gotoXY(x + 11, y++);
	cout << "|__   \"\"-._ |##               . . .";
	gotoXY(x + 11, y++);
	cout << "|  \"\"|-\"\"\" - _ / ##              . .";
	gotoXY(x + 11, y++);
	cout << "/\"\"--\\__.-|                       .";
	gotoXY(x + 11, y++);
	cout << "\\-_.-<__ /                   .   .";
	gotoXY(x + 11, y++);
	cout << "/-_| /  \\";
	gotoXY(x + 11, y++);
	cout << "\\-_| \\_-<.                        .  .";
	gotoXY(x + 11, y++);
	cout << "<_-/ <_.-\\                    .";
	gotoXY(x + 11, y++);
	cout << "<_-|  |_.-|                        .";
	gotoXY(x + 6, y++);
	cout << ".----|   \\__\\  |                 .";
	gotoXY(x + 5, y++);
	cout << "|     .\"\"\"   '.  |                       .";
	gotoXY(x + 6, y++);
	cout << ".___|        |__|";
	x = 20;
	y = 20;
	gotoXY(x, y++);
	cout << "$$$$$$$\\";
	gotoXY(x, y++);
	cout << "$$  __$$\\";
	gotoXY(x, y++);
	cout << "$$ |  $$ |$$\\   $$\\  $$$$$$\\";
	gotoXY(x, y++);
	cout << "$$$$$$$\\ |$$ |  $$ |$$  __$$\\";
	gotoXY(x, y++);
	cout << "$$  __$$\\ $$ |  $$ |$$$$$$$$ |";
	gotoXY(x, y++);
	cout << "$$ |  $$ |$$ |  $$ |$$   ____|";
	gotoXY(x, y++);
	cout << "$$$$$$$  |\\$$$$$$$ |\\$$$$$$$\\";
	gotoXY(x, y++);
	cout << "\\_______/  \\____$$ | \\_______|";
	gotoXY(x + 11, y++);
	cout << "$$\\   $$ | ";
	gotoXY(x + 11, y++);
	cout << "\\$$$$$$  |";
	gotoXY(x + 12, y++);
	cout << "\\______/";
	Sleep(2000);

}
void bang_thua()
{
	int x_new = 35;
	int x_chu = 0;
	int x = 65;
	int y = 10, y_dif = 0;
	// ==========================================================================
	SetColor(6);
	gotoXY(x + 25, y++);
	cout << ".-.";
	gotoXY(x + 25, y++);
	cout << "'-'";
	gotoXY(x + 24, y++);
	cout << "//";
	gotoXY(x + 23, y++);
	cout << "_..---._/|";
	gotoXY(x + 15, y++);
	cout << ".' .\"     '-.";
	gotoXY(x + 13, y++);
	cout << "/__/          \\      *";
	gotoXY(x + 11, y++);
	cout << "====_____     __|     :";
	gotoXY(x + 10, y++);
	cout << "/#   #\"\"\" |   /()\    :    ..*";
	gotoXY(x + 10, y++);
	cout << "|#   #    |   \\__/    : .''";
	gotoXY(x + 10, y++);
	cout << "\\#___#____|      /   :::.. .";
	gotoXY(x + 9, y++);
	cout << "\\______________|_...ä_: .. '*";
	gotoXY(x + 2, y++);
	cout << "()       // /\\||||)))))))      '   . .";
	gotoXY(x + 1, y++);
	cout << ".( \\_     \\\\_\\//   _-'.'/        |   * ..";
	gotoXY(x, y++);
	cout << "( )  |^|^|^|ooo/  _#\\.//\"\"\"_ | . . .";
	gotoXY(x, y++);
	cout << "(_)_.'v|v|v|     / \#  \\_ / '_  _'    . .";
	gotoXY(x + 11, y++);
	cout << "| _ _/_/     /'./_-|\"         . .";
	gotoXY(x + 11, y++);
	cout << "/#_#__\"\"\" - ._ / #  \\__)       .  .";
	gotoXY(x + 11, y++);
	cout << "|__   \"\"-._ |##               . . .";
	gotoXY(x + 11, y++);
	cout << "|  \"\"|-\"\"\" - _ / ##              . .";
	gotoXY(x + 11, y++);
	cout << "/\"\"--\\__.-|                       .";
	gotoXY(x + 11, y++);
	cout << "\\-_.-<__ /                   .   .";
	gotoXY(x + 11, y++);
	cout << "/-_| /  \\";
	gotoXY(x + 11, y++);
	cout << "\\-_| \\_-<.                        .  .";
	gotoXY(x + 11, y++);
	cout << "<_-/ <_.-\\                    .";
	gotoXY(x + 11, y++);
	cout << "<_-|  |_.-|                        .";
	gotoXY(x + 6, y++);
	cout << ".----|   \\__\\  |                 .";
	gotoXY(x + 5, y++);
	cout << "|     .\"\"\"   '.  |                       .";
	gotoXY(x + 6, y++);
	cout << ".___|        |__|";
	x = 20;
	y = 15;
	gotoXY(x + 2, y++);
	cout << "/$$$$$$";
	gotoXY(x + 1, y++);
	cout << "/$$__  $$";
	gotoXY(x, y++);
	cout << "| $$  \\__/  /$$$$$$  /$$$$$$/$$$$   /$$$$$$ ";
	gotoXY(x, y++);
	cout << "| $$ /$$$$ |____  $$| $$_  $$_  $$ /$$__  $$";
	gotoXY(x, y++);
	cout << "| $$|_  $$  /$$$$$$$| $$ \\ $$ \\ $$| $$$$$$$$";
	gotoXY(x, y++);
	cout << "| $$  \\ $$ /$$__  $$| $$ | $$ | $$| $$_____/";
	gotoXY(x, y++);
	cout << "|  $$$$$$/|  $$$$$$$| $$ | $$ | $$|  $$$$$$$";
	gotoXY(x + 1, y++);
	cout << "\\______/  \\_______/|__/ |__/ |__/ \\_______/";
	y += 3;
	gotoXY(x + 2, y++);
	cout << "/$$$$$$";
	gotoXY(x + 1, y++);
	cout << "/$$__  $$";
	gotoXY(x, y++);
	cout << "| $$  \\ $$ /$$    /$$ /$$$$$$   /$$$$$$";

	gotoXY(x, y++);
	cout << "| $$  | $$|  $$  /$$//$$__  $$ /$$__  $$";
	gotoXY(x, y++);
	cout << "| $$  | $$ \\  $$/$$/| $$$$$$$$| $$  \\__/";
	gotoXY(x, y++);
	cout << "| $$  | $$  \\  $$$/ | $$_____/| $$";
	gotoXY(x, y++);
	cout << "|  $$$$$$/   \\  $/  |  $$$$$$$| $$";
	gotoXY(x + 1, y++);
	cout << "\\______/     \\_/    \\_______/|__/";
	Sleep(5000);
	system("cls");
	reset();
	bang_menu();
}
void bang_menu()
{

	int x_new = 35;
	int x_chu = 0;
	int x = 68;
	int y = 10, y_dif = 0;
	// =============================Phi hành gia ========================================
	SetColor(11);
	gotoXY(x + 25, y++);
	cout << ".-.";
	gotoXY(x + 25, y++);
	cout << "'-'";
	gotoXY(x + 24, y++);
	cout << "//";
	gotoXY(x + 23, y++);
	cout << "_..---._/|";
	gotoXY(x + 15, y++);
	cout << ".' .\"     '-.";
	gotoXY(x + 13, y++);
	cout << "/__/          \\      *";
	gotoXY(x + 11, y++);
	cout << "====_____     __|     :";
	gotoXY(x + 10, y++);
	cout << "/#   #\"\"\" |   /()\    :    ..*";
	gotoXY(x + 10, y++);
	cout << "|#   #    |   \\__/    : .''";
	gotoXY(x + 10, y++);
	cout << "\\#___#____|      /   :::.. .";
	gotoXY(x + 9, y++);
	cout << "\\______________|_...ä_: .. '*";
	SetColor(11);
	gotoXY(x + 2, y++);
	cout << "()       // /\\||||)))))))      '   . .";
	gotoXY(x + 1, y++);
	cout << ".( \\_     \\\\_\\//   _-'.'/        |   * ..";
	gotoXY(x, y++);
	cout << "( )  |^|^|^|ooo/  _#\\.//\"\"\"_ | . . .";
	gotoXY(x, y++);
	cout << "(_)_.'v|v|v|     / \#  \\_ / '_  _'    . .";
	gotoXY(x + 11, y++);
	cout << "| _ _/_/     /'./_-|\"         . .";
	gotoXY(x + 11, y++);
	cout << "/#_#__\"\"\" - ._ / #  \\__)       .  .";
	gotoXY(x + 11, y++);
	cout << "|__   \"\"-._ |##               . . .";
	gotoXY(x + 11, y++);
	cout << "|  \"\"|-\"\"\" - _ / ##              . .";
	gotoXY(x + 11, y++);
	cout << "/\"\"--\\__.-|                       .";
	gotoXY(x + 11, y++);
	cout << "\\-_.-<__ /                   .   .";
	gotoXY(x + 11, y++);
	cout << "/-_| /  \\";
	gotoXY(x + 11, y++);
	cout << "\\-_| \\_-<.                        .  .";
	gotoXY(x + 11, y++);
	cout << "<_-/ <_.-\\                    .";
	gotoXY(x + 11, y++);
	cout << "<_-|  |_.-|                        .";
	gotoXY(x + 6, y++);
	cout << ".----|   \\__\\  |                 .";
	gotoXY(x + 5, y++);
	cout << "|     .\"\"\"   '.  |                       .";
	gotoXY(x + 6, y++);
	cout << ".___|        |__|";

	//============ Pháo bông ====================

	// ==========================================================================
	y = 1;
	int x_tua_game = 10;
	SetColor(6);
	gotoXY(x_tua_game + 1, y++);
	cout << "________  __        __                            _______   __                            __";
	gotoXY(x_tua_game, y++);
	cout << "/        |/  |      /  |                          /       \\ /  |                          /  |";
	gotoXY(x_tua_game, y++);
	cout << "$$$$$$$$/ $$ |____  $$/   ______   _______        $$$$$$$  |$$ |____   __    __   _______ $$/   _______";
	gotoXY(x_tua_game + 4, y++);
	cout << "$$ |   $$      \\ /  | /      \\ /       \\       $$ |__$$ |$$      \\ /  |  /  | /       |$/   /       |";
	gotoXY(x_tua_game + 4, y++);
	cout << "$$ |   $$$$$$$  |$$ |/$$$$$$  |$$$$$$$  |      $$    $$/ $$$$$$$  |$$ |  $$ |/$$$$$$$/     /$$$$$$$/ ";
	gotoXY(x_tua_game + 4, y++);
	cout << "$$ |   $$ |  $$ |$$ |$$    $$ |$$ |  $$ |      $$$$$$$/  $$ |  $$ |$$ |  $$ |$$ |          $$      \\";
	gotoXY(x_tua_game + 4, y++);
	cout << "$$ |   $$ |  $$ |$$ |$$$$$$$$/ $$ |  $$ |      $$ |      $$ |  $$ |$$ \\__$$ |$$ \\_____      $$$$$$  |";
	gotoXY(x_tua_game + 4, y++);
	cout << "$$ |   $$ |  $$ |$$ |$$       |$$ |  $$ |      $$ |      $$ |  $$ |$$    $$/ $$       |    /     $$/";
	gotoXY(x_tua_game + 4, y++);
	cout << "$$/    $$/   $$/ $$/  $$$$$$$/ $$/   $$/       $$/       $$/   $$/  $$$$$$/   $$$$$$$/     $$$$$$$/";
	gotoXY(x_tua_game + 1, y++);
	cout << "______                       __";
	gotoXY(x_tua_game, y++);
	cout << "/      \\                     /  |";
	gotoXY(x_tua_game, y++);
	cout << "/$$$$$$  | _______    ______  $$ |   __   ______";
	gotoXY(x_tua_game, y++);
	cout << "$$ \\__$$/ /       \\  /      \\ $$ |  /  | /      \\";
	gotoXY(x_tua_game, y++);
	cout << "$$      \\ $$$$$$$  | $$$$$$  |$$ |_/$$/ /$$$$$$  |";
	gotoXY(x_tua_game + 1, y++);
	cout << "$$$$$$  |$$ |  $$ | /    $$ |$$   $$<  $$    $$ |";
	gotoXY(x_tua_game, y++);
	cout << "/  \\__$$ |$$ |  $$ |/$$$$$$$ |$$$$$$  \ $$$$$$$$/ ";
	gotoXY(x_tua_game, y++);
	cout << "$$    $$/ $$ |  $$ |$$    $$ |$$ | $$  |$$       |";
	gotoXY(x_tua_game + 1, y++);
	cout << "$$$$$$ / $$ / $$ / $$$$$$$ / $$ / $$ / $$$$$$$ /";
	//==============================================================
	x = 4;
	y = 21;
	SetColor(6);
	gotoXY(x + 1, y);
	cout << "_________________________________________________________";
	gotoXY(x, y + 1);
	cout << "==| |  || |                                  |  ||  | |==";
	gotoXY(x, y + 2);
	cout << "==/ / // /         1. New game               /  //  / /==";
	gotoXY(x, y + 3);
	cout << "==\\ \\ \\\\ \\         2. More Information       \\ \\\\  \\ \\==";
	gotoXY(x, y + 4);
	cout << "==| |  ||          3. Exit                    \\ \\\\   \\ \\==";
	gotoXY(x + 1, y + 5);
	cout << "==|_|__||_|___________________________________|_||___|_|==";
	int choose = 0;
	int k = 0;
	int x_phao = 68;
	while (true)
	{
		if (k % 40 != 0)
		{
			SetColor(13);
			gotoXY(x_phao + 34, 16);
			cout << "*";
			gotoXY(x_phao + 34, 15);
			cout << "*";
			gotoXY(x_phao + 38, 17);
			cout << "*";
			gotoXY(x_phao + 40, 18);
			cout << "*";
			gotoXY(x_phao + 32, 19);
			cout << "*";
			gotoXY(x_phao + 34, 20);
			cout << "*";
			gotoXY(x_phao + 40, 21);
			cout << "*";
			gotoXY(x_phao + 32, 22);
			cout << "*";
			gotoXY(x_phao + 34, 23);
			cout << "*";
			gotoXY(x_phao + 34, 24);
			cout << "*";
			gotoXY(x_phao + 40, 25);
			cout << "*";
			SetColor(14);
			gotoXY(x_phao + 36, 15);
			cout << "*";
			gotoXY(x_phao + 32, 16);
			cout << "*";
			gotoXY(x_phao + 39, 17);
			cout << "*";
			gotoXY(x_phao + 42, 18);
			cout << "*";
			gotoXY(x_phao + 31, 19);
			cout << "*";
			gotoXY(x_phao + 32, 20);
			cout << "*";
		}
		else
		{
			SetColor(13);
			gotoXY(x_phao + 34, 16);
			cout << " ";
			gotoXY(x_phao + 34, 15);
			cout << " ";
			gotoXY(x_phao + 38, 17);
			cout << " ";
			gotoXY(x_phao + 40, 18);
			cout << " ";
			gotoXY(x_phao + 32, 19);
			cout << " ";
			gotoXY(x_phao + 34, 20);
			cout << " ";
			gotoXY(x_phao + 40, 21);
			cout << " ";
			gotoXY(x_phao + 32, 22);
			cout << " ";
			gotoXY(x_phao + 34, 23);
			cout << " ";
			gotoXY(x_phao + 34, 24);
			cout << " ";
			gotoXY(x_phao + 40, 25);
			cout << " ";
			SetColor(14);
			gotoXY(x_phao + 36, 15);
			cout << " ";
			gotoXY(x_phao + 32, 16);
			cout << " ";
			gotoXY(x_phao + 39, 17);
			cout << " ";
			gotoXY(x_phao + 42, 18);
			cout << " ";
			gotoXY(x_phao + 31, 19);
			cout << " ";
			gotoXY(x_phao + 32, 20);
			cout << " ";
		}

		k++;
		if (_kbhit() == true)
		{
			c = _getch();
			if (c == '1')
			{
				SetColor(6);
				gotoXY(x, y + 2);
				cout << "==/ / // /         1. New game               /  //  / /==";
				gotoXY(x, y + 3);
				cout << "==\\ \\ \\\\ \\         2. More Information       \\ \\\\  \\ \\==";
				gotoXY(x, y + 4);
				cout << "==| |  ||          3. Exit                    \\ \\\\   \\ \\==";
				SetColor(11);
				gotoXY(x + 16, y + 2);
				cout << "->";
				choose = 1;
			}
			else if (c == '2')
			{
				SetColor(6);
				gotoXY(x, y + 2);
				cout << "==/ / // /         1. New game               /  //  / /==";
				gotoXY(x, y + 3);
				cout << "==\\ \\ \\\\ \\         2. More Information       \\ \\\\  \\ \\==";
				gotoXY(x, y + 4);
				cout << "==| |  ||          3. Exit                    \\ \\\\   \\ \\==";
				SetColor(11);
				gotoXY(x + 16, y + 3);
				cout << "->";
				choose = 2;

			}
			else if (c == '3')
			{
				SetColor(6);
				gotoXY(x, y + 2);
				cout << "==/ / // /         1. New game               /  //  / /==";
				gotoXY(x, y + 3);
				cout << "==\\ \\ \\\\ \\         2. More Information       \\ \\\\  \\ \\==";
				gotoXY(x, y + 4);
				cout << "==| |  ||          3. Exit                    \\ \\\\   \\ \\==";
				SetColor(11);
				gotoXY(x + 16, y + 4);
				cout << "->";
				choose = 3;
			}
			else if (c == 13)
			{
				if (choose == 1)
				{
					system("cls");
					chay_game();
				}
				else if (choose == 2)
				{
					system("cls");
					SetColor(15);
					cout << "\n\n\nCreator: Pham Huy Thien Phuc\n";
					cout << "\nDate: 24/01/2022\n";
					SetColor(8);
					cout << " \n\n\t\t==========================  Story  ==========================\n\n";
					cout << "\t\t\t\tYou are a mother snake in the small garden.\n\t\t\t\tYour son is a strong snake who can puff fire.\n";
					cout << "\t\t\t\tThe main mission of this game is to make the villagers around you happy.\n\t\t\t\tNow, it have just completed round 1.\n\n";
					cout << "\t\t\t\t\t\t\t\t\tEnjoy the game,\n";
					cout << "\t\t\t\t\t\t\t\t\tPham Huy Thien Phuc.\n";
					Sleep(8500);
					system("cls");
					bang_menu();
					break;
				}
				else if (choose == 3)
				{
					system("cls");
					bang_thoat();
					Sleep(8000);
					break;
				}
			}
		}
	}
}
// ==================  Các hàm tạo - vẽ nhân vật  ========================
// ============= Tường,khung điểm =================
void ve_khung_diem(int hp, int gold, int flower, bool gem)
{
	//int y_dif = 20;
	SetColor(13);
	char c = 204;
	gotoXY(100, 18);
	cout << c;
	c = 205;
	for (int x = 101; x <= 118; x++)
	{
		gotoXY(x, 18); cout << c;
		gotoXY(x, 27); cout << c;
	}
	SetColor(12);
	gotoXY(105, 20);
	cout << "Gold: " << gold << endl;
	gotoXY(105, 22);
	cout << "Flower: " << flower << endl;
	if (gem == true)
	{
		gotoXY(105, 24);
		cout << "Gem: Yes" << endl;
	}
	else
	{
		gotoXY(113, 24);
		cout << "  ";
		gotoXY(105, 24);
		cout << "Gem: No " << endl;
	}
	gotoXY(105, 26);
	cout << "HP: " << me_hp << endl;


}
bool ban_trung_qua(int x, int y)
{
	return (x == qua_x && y == qua_y);
}
bool ban_trung_hoa(int x, int y)
{
	return (x == hoa_x && y == hoa_y);
}
void ve_tuong()
{
	// =============== Vẽ cây =================

	int y = 2;
	for (int x = 1; x <= 2; x++)
	{
		SetColor(10);
		gotoXY(5, y);
		cout << "A";
		gotoXY(4, ++y);
		cout << "/I\\";
		gotoXY(3, ++y);
		cout << "//I\\\\ ";
		gotoXY(2, ++y);
		cout << "///I\\\\\\";
		gotoXY(2, ++y);
		cout << "'//I\\\\'";
		gotoXY(4, ++y);
		SetColor(6);
		cout << "'I'";
		gotoXY(4, ++y);
		y += 2;
	}
	// ============= Vẽ chim =============
	SetColor(4);
	gotoXY(3, y);
	cout << "\\\\";
	SetColor(14);
	gotoXY(3, ++y);
	cout << "(o>";
	gotoXY(2, ++y);
	SetColor(9);
	cout << "_(()_";
	gotoXY(3, ++y);
	SetColor(9);
	cout << "||";
	y += 1;
	SetColor(4);
	gotoXY(4, y);
	cout << "\\\\";
	SetColor(14);
	gotoXY(4, ++y);
	cout << "(o>";
	gotoXY(1, ++y);
	SetColor(9);
	cout << "\\\\_//)";
	gotoXY(2, ++y);
	SetColor(9);
	cout << "\\_/_)";
	SetColor(6);
	gotoXY(3, ++y);
	cout << "_|_";


	// ===================== Vẽ đất ===============

	for (int i = 2; i <= 8; i++)
	{
		gotoXY(i, 8); cout << "+";
		gotoXY(i, 16); cout << "+";
	}

	// ===================== Vẽ khung =============

	char c = 205;
	SetColor(13);
	for (int x = 1; x <= 9; x++)
	{
		gotoXY(x, 1); cout << c;
		gotoXY(x, 27); cout << c;
	}
	for (int x = 11; x <= 99; x++)
	{
		gotoXY(x, 1); cout << c;
		gotoXY(x, 27); cout << c;
	}
	for (int x = 101; x <= 118; x++)
	{
		gotoXY(x, 1); cout << c;
		gotoXY(x, 27); cout << c;
	}
	c = 186;
	for (int y = 2; y <= 26; y++)
	{
		gotoXY(10, y); cout << c;
	}
	for (int y = 2; y <= 26; y++)
	{
		gotoXY(100, y); cout << c;
	}

	// =============== Vẽ góc cạnh ===========
	c = 203;
	gotoXY(10, 1); cout << c;
	gotoXY(100, 1); cout << c;
	c = 202;
	gotoXY(10, 27); cout << c;
	gotoXY(100, 27); cout << c;
	// ================= Vẽ khỉ ===================
	int y_dif = 2;
	SetColor(7);
	gotoXY(108, y_dif);
	cout << "_       _";
	gotoXY(107, ++y_dif);
	cout << "{ \"-   .\" }";
	SetColor(11);
	gotoXY(102, ++y_dif);
	cout << "\\_   /\\\\    //\\";
	SetColor(14);
	gotoXY(102, ++y_dif);
	cout << "  \\_| ||    || |_/";
	y_dif += 1;
	SetColor(6);
	gotoXY(108, ++y_dif);
	cout << "/   //   /";
	gotoXY(107, ++y_dif);
	cout << "/   //   /";
	gotoXY(106, ++y_dif);
	cout << "/   //   /";
	gotoXY(105, ++y_dif);
	cout << "/   //   /";
	gotoXY(104, ++y_dif);
	cout << "/   //   /";
	SetColor(14);
	gotoXY(113, y_dif);
	cout << "x";
	gotoXY(102, ++y_dif);
	cout << ".-. _______|__";
	gotoXY(102, ++y_dif);
	cout << "|=|/  tho ren \\";
	gotoXY(102, ++y_dif);
	cout << "|-|-----------|";
	SetColor(15);
	gotoXY(102, ++y_dif);
	cout << "| |_____|_\"\"__|";
	gotoXY(102, ++y_dif);
	cout << "|_|_[X]_|_____|";
}
void ve_chuot()
{
	m.lock();
	SetColor(6);
	gotoXY(x_chuot, y_chuot);
	cout << "()-().----.:";
	gotoXY(x_chuot + 1, y_chuot + 1);
	cout << "\\\"/` ___  ;__.";
	gotoXY(x_chuot + 2, y_chuot + 2);
	cout << "` ^^   ^^";
	m.unlock();
}
void xoa_chuot_them_hoa()
{
	m.lock();
	gotoXY(x_chuot, y_chuot);
	cout << "            ";
	gotoXY(x_chuot + 1, y_chuot + 1);
	cout << "              ";
	gotoXY(x_chuot + 2, y_chuot + 2);
	cout << "         ";
	SetColor(2);
	gotoXY(103, 7);
	cout << "~~~";
	SetColor(6);
	gotoXY(102, 8);
	cout << "((@))";
	SetColor(2);
	gotoXY(104, 9);
	cout << "|";
	SetColor(10);
	gotoXY(x_ran_co_dai + 4, y_ran_co_dai + 1);
	cout << "Y";
	gotoXY(x_ran_co_dai + 2, y_ran_co_dai + 2);
	cout << ".-^-.";
	gotoXY(x_ran_co_dai + 1, y_ran_co_dai + 3);
	cout << "/     \\      .- ~ ~ -.";
	gotoXY(x_ran_co_dai, y_ran_co_dai + 4);
	cout << "()     ()    /   _ _   `.                     _ _ _";
	gotoXY(x_ran_co_dai + 1, y_ran_co_dai + 5);
	cout << "\\_   _/    /  /     \\   \\                . ~  _ _  ~ .";
	gotoXY(x_ran_co_dai + 3, y_ran_co_dai + 6);
	cout << "| |     /  /       \\   \\             .' .~       ~-. `.";
	gotoXY(x_ran_co_dai + 3, y_ran_co_dai + 7);
	cout << "| |    /  /         )   )           /  /             `.`.";
	gotoXY(x_ran_co_dai + 3, y_ran_co_dai + 8);
	cout << "\\ \\_ _/  /         /   /           /  /                `'";
	gotoXY(x_ran_co_dai + 4, y_ran_co_dai + 9);
	cout << "\\_ _ _.'         /   /           (  (";
	gotoXY(x_ran_co_dai + 20, y_ran_co_dai + 10);
	cout << "/   /             \\  \\";
	gotoXY(x_ran_co_dai + 19, y_ran_co_dai + 11);
	cout << "/   /               \\  \\";
	gotoXY(x_ran_co_dai + 18, y_ran_co_dai + 12);
	cout << "/   /                 )  )";
	gotoXY(x_ran_co_dai + 17, y_ran_co_dai + 13);
	cout << "(   (                 /  /";
	gotoXY(x_ran_co_dai + 18, y_ran_co_dai + 14);
	cout << "`.  `.             .'  /";
	gotoXY(x_ran_co_dai + 20, y_ran_co_dai + 15);
	cout << "`.   ~ - - - - ~   .'";
	gotoXY(x_ran_co_dai + 23, y_ran_co_dai + 16);
	cout << "~ . _ _ _ _ . ~";
	gotoXY(x_ran_co_dai + 22, y_ran_co_dai + 30);
	cout << " ";
	m.unlock();
}
// ========= Rắn mẹ =============
void tao_ran_me()
{
	int x = 50; int y = 14;
	for (int i = 0; i < me_hp; i++)
	{
		me_x[i] = x;
		me_y[i] = y;
		x--;
	}
}
void ve_ran_me()
{

	for (int i = 0; i < me_hp; i++)
	{
		gotoXY(me_x[i], me_y[i]);
		if (i == 0)
		{
			cout << "0";
		}
		else
		{
			cout << "o";
		}
	}
}
void me_di_chuyen(int x, int y)
{
	//Dời
	for (int i = me_hp; i > 0; i--)
	{
		me_x[i] = me_x[i - 1];
		me_y[i] = me_y[i - 1];
	}
	//chèn
	me_x[0] = x;
	me_y[0] = y;
}
bool ban_trung_vang(int x, int y)
{

	for (int i = 0; i < sl_vang; i++)
	{
		if (x == vang_x[i] && y == vang_y[i])
		{
			return true;
		}
	}
	return false;
}
// ========= Rắn con ============
void tao_ran_con()
{
	int xn = 49; int yn = 13;
	for (int i = 0; i < 2; i++)
	{
		con_x[i] = xn;
		con_y[i] = yn;
		xn--;
	}
}
void ve_ran_con(bool tien_hoa)
{
	char c = 1;
	char c_tien_hoa = 1;
	char duoi_tien_hoa = 147;
	for (int i = 0; i < 2; i++)
	{
		gotoXY(con_x[i], con_y[i]);
		if (!tien_hoa)
		{
			if (i == 0)
			{
				cout << c;
			}
			else
			{
				cout << "o";
			}
		}
		else
		{
			if (i == 0)
			{
				cout << c_tien_hoa;
			}
			else
			{
				cout << duoi_tien_hoa;
			}
		}
	}
}
void ran_de_quai()
{

	for (int i = 0; i < me_hp; i++)
	{
		if (ban_trung_sau(me_x[i], me_y[i]))
		{
			cnt++;
			if (cnt == 3)
			{
				m.lock();
				gotoXY(me_x[me_hp - 1], me_y[me_hp - 1]);
				cout << " ";
				m.unlock();
				me_hp--;
				cnt = 0;
			}
		}
		if (ban_trung_nhen(me_x[i], me_y[i]))
		{
			cnt++;
			if (cnt == 3)
			{
				m.lock();
				gotoXY(me_x[me_hp - 1], me_y[me_hp - 1]);
				cout << " ";
				m.unlock();
				me_hp--;
				cnt = 0;
			}
		}
	}

}
void ve_vang()
{
	for (int k = 0; k < sl_vang; k++)
	{
		if (vang_x[k] != -99 && vang_y[k] != -99)
		{
			SetColor(14);
			gotoXY(vang_x[k], vang_y[k]);
			cout << "$";
		}
	}
}
void tia_lua(int choose)
{
	int length = 0;
	if (tien_hoa)length = 20;
	else length = 3;
	if (choose == 0)
	{
		int x = con_x[0];
		int y = con_y[0];
		for (int i = 1; i <= length; i++)
		{

			if (y + i >= 26)
			{
				break;
			}
			else
			{
				gotoXY(x, y + i);
				cout << "A";
				if (ban_trung_sau(x, y + i) && tien_hoa)
				{
					hp_sau--;
				}
				if (ban_trung_nhen(x, y + i))
				{
					hp_nhen--;
				}
				if (ban_trung_hoa(x, y + i))
				{
					xoa_hoa();
					tao_hoa();
				}
				if (ban_trung_qua(x, y + i))
				{
					tao_qua();
				}
			}

		}
		Sleep(40);
		for (int i = 1; i <= length; i++)
		{

			if (y + i >= 26)
			{
				break;
			}
			else
			{
				gotoXY(x, y + i);
				cout << " ";
			}
		}
	}
	else if (choose == 1)
	{
		int x = con_x[0];
		int y = con_y[0];
		for (int i = 1; i <= length; i++)
		{

			if (y - i <= 2)
			{
				break;
			}
			else
			{
				gotoXY(x, y - i);
				cout << "A";
				if (ban_trung_sau(x, y - i) && tien_hoa)
				{
					hp_sau--;
				}
				if (ban_trung_nhen(x, y - i))
				{
					hp_nhen--;
				}
				if (ban_trung_hoa(x, y - i))
				{
					xoa_hoa();
					tao_hoa();
				}
				if (ban_trung_qua(x, y - i))
				{
					tao_qua();
				}
			}

		}
		Sleep(40);
		for (int i = 1; i <= length; i++)
		{

			if (y - i <= 2)
			{
				break;
			}
			else
			{
				gotoXY(x, y - i);
				cout << " ";
			}
		}
	}
	else if (choose == 3)
	{
		int x = con_x[0];
		int y = con_y[0];
		for (int i = 1; i <= length; i++)
		{

			if (x - i <= 10)
			{
				break;
			}
			else
			{
				gotoXY(x - i, y);
				cout << "A";
				if (ban_trung_sau(x - i, y) && tien_hoa)
				{
					hp_sau--;
				}
				if (ban_trung_nhen(x - i, y))
				{
					hp_nhen--;
				}
				if (ban_trung_hoa(x - i, y))
				{
					xoa_hoa();
					tao_hoa();
				}
				if (ban_trung_qua(x - i, y))
				{
					tao_qua();
				}
			}

		}
		Sleep(40);
		for (int i = 1; i <= length; i++)
		{

			if (x - i <= 10)
			{
				break;
			}
			else
			{
				gotoXY(x - i, y);
				cout << " ";
			}
		}
	}
	else if (choose == 2)
	{
		int x = con_x[0];
		int y = con_y[0];
		for (int i = 1; i <= length; i++)
		{

			if (x + i >= 100)
			{
				break;
			}
			else
			{
				gotoXY(x + i, y);
				cout << "A";
				if (ban_trung_sau(x + i, y) && tien_hoa)
				{
					hp_sau--;
				}
				if (ban_trung_nhen(x + i, y))
				{
					hp_nhen--;
				}
				if (ban_trung_hoa(x + i, y))
				{
					xoa_hoa();
					tao_hoa();
				}
				if (ban_trung_qua(x + i, y))
				{
					tao_qua();
				}
			}

		}
		Sleep(40);
		for (int i = 1; i <= length; i++)
		{

			if (x + i >= 100)
			{
				break;
			}
			else
			{
				gotoXY(x + i, y);
				cout << " ";
			}
		}
	}
	ve_vang();
}
void xoa_hoa()
{
	SetColor(0);
	gotoXY(hoa_x, hoa_y - 2);
	cout << "  ";
	gotoXY(hoa_x - 1, hoa_y - 1);
	cout << "    ";
	gotoXY(hoa_x - 2, hoa_y);
	cout << "       ";
	gotoXY(hoa_x - 1, hoa_y + 1);
	cout << "    ";
}
void skill_ran_con()
{
	int cnt = 0;
	//---- setting ---
	while (game_over == false)
	{
		m.lock();
		if (c == 32)
		{
			SetColor(5);
			tia_lua(check);
		}
		m.unlock();
		c = 0;
	}
}
void con_di_chuyen(int x, int y)
{
	//Dời
	for (int i = 2; i > 0; i--)
	{
		con_x[i] = con_x[i - 1];
		con_y[i] = con_y[i - 1];
	}
	//chèn
	con_x[0] = x;
	con_y[0] = y;
}

// ========= Sâu, vàng ==========
bool ban_trung_sau(int x, int y)
{
	return ((x == sau_x && y == sau_y - 2) || (x == sau_x && y == sau_y) || (x == sau_x && y == sau_y + 1) || (x == sau_x + 1 && y == sau_y + 1) || (x == sau_x + 2 && y == sau_y + 1) || (x == sau_x + 2 && y == sau_y) || (x == sau_x + 2 && y == sau_y - 2) || (x == sau_x + 1 && y == sau_y - 1));

}
bool sau_an_hoa()
{
	float kc = abs(pow(sau_x + 1 - hoa_x + 1, 2) + pow(sau_y - hoa_y, 2));
	return kc <= 4.5;
}
bool ve_sau()
{
	bool flag = true;
	m.lock();
	switch (hp_sau)
	{
	case 8:
		SetColor(4);
		break;
	case 7:
		SetColor(3);
		break;
	case 6:
		SetColor(9);
		break;
	case 5:
		SetColor(8);
		break;
	case 4:
		SetColor(5);
		break;
	case 3:
		SetColor(4);
		break;
	case 2:
		SetColor(3);
		break;
	case 1:
		SetColor(2);
		break;
	default:
		SetColor(14);
		gotoXY(sau_x, sau_y);
		cout << "$";
		vang_x[sl_vang] = sau_x;
		vang_y[sl_vang] = sau_y;
		sau_x = -99;
		sau_y = -99;
		sl_vang++;
		flag = false;
		break;
	}
	m.unlock();
	m.lock();
	if (flag)
	{
		gotoXY(sau_x, sau_y - 2);
		cout << "\\ /";
		gotoXY(sau_x, sau_y - 1);
		cout << ">v<";
		gotoXY(sau_x, sau_y);
		cout << ">O<";
		gotoXY(sau_x, sau_y + 1);
		cout << ">O<";
	}
	m.unlock();
	return flag;
}
void sau_di_chuyen()
{
	int cnt = 1;
	while (true)
	{
		if (game_over == true)
		{
			return;
		}
		if (ran_co_dai && cnt)
		{
			Sleep(5000);
			cnt = 0;
		}
		if (!ve_sau())
		{
			break;
		}
		Sleep(70);
		m.lock();
		gotoXY(sau_x, sau_y - 2);
		cout << "   ";
		gotoXY(sau_x, sau_y - 1);
		cout << "   ";
		gotoXY(sau_x, sau_y);
		cout << "   ";
		gotoXY(sau_x, sau_y + 1);
		cout << "   ";
		sau_y--;
		m.unlock();
		if (sau_y == 3)
		{
			sau_y = 25;
		}
	}
}
// ========= Quả ===========
void tao_qua()
{
	do
	{
		qua_x = rand() % (98 - 12 + 1) + 12;
		qua_y = rand() % (25 - 2 + 1) + 2;
	} while (kt_ran_de_qua() == true);
}
bool kt_ran_de_qua()
{
	for (int i = 0; i < me_hp; i++)
	{
		if (qua_x == me_x[i] && qua_y == me_y[i])
		{
			return true;
		}
	}
	return false;
}
void ve_qua()
{
	char c = 3;
	m.lock();
	gotoXY(qua_x, qua_y); SetColor(4);
	cout << c;
	m.unlock();
}
bool kt_ran_an_qua()
{
	if ((me_x[0] == qua_x && me_y[0] == qua_y) || (con_x[0] == qua_x && con_y[0] == qua_y))
	{
		m.lock();
		gotoXY(qua_x, qua_y);
		cout << " ";
		m.unlock();
		return true;
	}
	return false;
}
// ========= Hoa ========
void tao_hoa()
{
	do
	{
		hoa_x = rand() % (97 - 15 + 1) + 15;
		hoa_y = rand() % (24 - 4 + 1) + 4;
	} while (kt_ran_de_hoa() == true);
}
bool kt_ran_de_hoa()
{

	for (int i = 0; i < me_hp; i++)
	{
		float kc_me_qua = sqrt(pow((me_x[i] - hoa_x), 2) + pow((me_y[i] - hoa_y), 2));
		float kc_con_qua = sqrt(pow((con_x[i] - hoa_x), 2) + pow((con_y[i] - hoa_y), 2));
		if (kc_con_qua < 1.44 || kc_me_qua < 1.44)
		{
			return true;
		}
	}
	return false;
}
bool kt_ran_an_vang()
{

	for (int i = 0; i < sl_vang; i++)
	{
		if ((me_x[0] == vang_x[i] && me_y[0] == vang_y[i]) || (con_x[0] == vang_x[i] && con_y[0] == vang_y[i]))
		{

			vang_x[i] = -99;
			vang_y[i] = -99;

			return true;
		}
	}
	return false;
}
void ve_hoa()
{
	m.lock();
	gotoXY(hoa_x, hoa_y - 2); SetColor(6);
	cout << "_";
	gotoXY(hoa_x - 1, hoa_y - 1);
	cout << "(_)";
	gotoXY(hoa_x - 2, hoa_y);
	cout << "(_@_)";
	gotoXY(hoa_x - 1, hoa_y + 1);
	cout << "(_)";
	SetColor(15);
	m.unlock();
}
bool kt_ran_an_hoa()
{


	if ((me_x[0] == hoa_x && me_y[0] == hoa_y - 2) || (me_x[0] == hoa_x - 1 && me_y[0] == hoa_y - 1) || (me_x[0] == hoa_x - 2 && me_y[0] == hoa_y) || (me_x[0] == hoa_x - 1 && me_y[0] == hoa_y + 1) || (me_x[0] == hoa_x && me_y[0] == hoa_y + 1) || (me_x[0] == hoa_x + 1 && me_y[0] == hoa_y + 1) || (me_x[0] == hoa_x + 2 && me_y[0] == hoa_y) || (me_x[0] == hoa_x + 1 && me_y[0] == hoa_y - 1))
	{
		m.lock();
		SetColor(0);
		gotoXY(hoa_x, hoa_y - 2);
		cout << "  ";
		gotoXY(hoa_x - 1, hoa_y - 1);
		cout << "    ";
		gotoXY(hoa_x - 2, hoa_y);
		cout << "       ";
		gotoXY(hoa_x - 1, hoa_y + 1);
		cout << "    ";
		m.unlock();
		return true;
	}
	return false;
}
//======================= Nhện =================
bool ve_nhen()
{
	bool flag = true;
	m.lock();
	switch (hp_nhen)
	{
	case 6:
		SetColor(9);
		break;
	case 5:
		SetColor(8);
		break;
	case 4:
		SetColor(5);
		break;
	case 3:
		SetColor(4);
		break;
	case 2:
		SetColor(3);
		break;
	case 1:
		SetColor(2);
		break;
	default:
		SetColor(14);
		gotoXY(nhen_x, nhen_y);
		cout << "$";
		int x = nhen_x;
		int y = nhen_y;
		nhen_x = -99;
		nhen_y = -99;
		vang_x[sl_vang] = x;
		vang_y[sl_vang] = y;
		sl_vang++;
		flag = false;
		break;
	}
	if (flag)
	{
		gotoXY(nhen_x + 2, nhen_y - 2);
		cout << "/ _ \\";
		gotoXY(nhen_x, nhen_y - 1);
		cout << "\\_\\(_)/_/";
		gotoXY(nhen_x + 1, nhen_y);
		cout << "_//o\\\\_";
		gotoXY(nhen_x + 2, nhen_y + 1);
		cout << "/   \\";
	}
	m.unlock();
	return flag;
}
void nhen_di_chuyen()
{
	int cnt = 1;
	while (true)
	{
		if (game_over == true)
		{
			return;
		}
		if (ran_co_dai && cnt)
		{
			Sleep(5000);
			cnt = 0;
		}
		if (!ve_nhen())
		{
			break;
		}
		Sleep(90);
		m.lock();
		gotoXY(nhen_x + 2, nhen_y - 2);
		cout << "     ";
		gotoXY(nhen_x, nhen_y - 1);
		cout << "         ";
		gotoXY(nhen_x + 1, nhen_y);
		cout << "       ";
		gotoXY(nhen_x + 2, nhen_y + 1);
		cout << "     ";
		nhen_x++;
		m.unlock();
		if (nhen_x == 92)
		{
			nhen_x = 13;
		}

	}
}
bool ban_trung_nhen(int x, int y)
{
	return ((x == nhen_x && y == nhen_y - 2) || (x == nhen_x && y == nhen_y) || (x == nhen_x && y == nhen_y + 1) || (x == nhen_x + 1 && y == nhen_y + 1) || (x == nhen_x + 2 && y == nhen_y + 1) || (x == nhen_x + 2 && y == nhen_y) || (x == nhen_x + 2 && y == nhen_y - 2) || (x == nhen_x + 1 && y == nhen_y - 1));

}
//================= Cổng 2 gold ================
void ve_cong()
{
	m.lock();
	char c = 188;
	gotoXY(100, 14);
	cout << c;
	gotoXY(100, 15);
	cout << " ";
	c = 187;
	gotoXY(100, 16);
	cout << c;
	c = 196;
	gotoXY(101, 16);
	cout << c;
	gotoXY(101, 14);
	cout << c;
	m.unlock();
}
// ==================== Hàm play ====================
void play()
{
	m.lock();
	ve_tuong();
	tao_ran_me();
	tao_ran_con();
	m.unlock();
	tao_qua();
	tao_hoa();
	int x = me_x[0];//50
	int y = me_y[0];//13
	int xn = con_x[0];//49
	int yn = con_y[0];//12
	bool cong = false;
	int cnt = 0;
	while (true)
	{
		m.lock();
		ve_vang();
		m.unlock();
		if (game_over == true)
		{
			system("cls");
			bang_thua();
			return;
		}
		m.lock();
		ve_khung_diem(me_hp, vang, hoa, gem);
		ShowCur(0);
		m.unlock();
		//---- backspace ----
		m.lock();
		gotoXY(me_x[me_hp], me_y[me_hp]);
		cout << " ";
		gotoXY(con_x[2], con_y[2]);
		cout << " ";
		m.unlock();
		//--- in --
		m.lock();
		SetColor(9);
		ve_ran_me();
		SetColor(12);
		ve_ran_con(tien_hoa);
		m.unlock();
		ve_qua();
		ve_hoa();
		ran_de_quai();
		//--- điều khiển để thay đổi hướng ---
		if (_kbhit() == true)
		{
			c = _getch();
			if (c == -32)
			{
				c = _getch();
				if (c == 72 && check != 0)
				{
					check = 1;
				}
				else if (c == 80 && check != 1)
				{
					check = 0;
				}
				else if (c == 75 && check != 2)
				{
					check = 3;
				}
				else if (c == 77 && check != 3)
				{
					check = 2;
				}
			}
		}
		if (me_hp <= 0)
		{
			game_over = true;
		}
		//--- dựa vào hướng để di chuyển ---
		if (check == 0)
		{
			y++;
			yn++;
		}
		else if (check == 1)
		{
			yn--;
			y--;
		}
		else if (check == 2)
		{
			x++;
			xn++;
		}
		else if (check == 3)
		{
			x--;
			xn--;
		}
		me_di_chuyen(x, y);
		con_di_chuyen(xn, yn);
		if (ban_trung_nhen(qua_x, qua_y))
		{
			tao_qua();
			m.lock();
			if (hp_nhen < 6)
			{
				hp_nhen++;
			}
			m.unlock();
		}
		if (sau_an_hoa())
		{
			m.lock();
			xoa_hoa();
			m.unlock();
			tao_hoa();
			m.lock();
			if (hp_sau < 8)
			{
				hp_sau++;
			}
			m.unlock();
		}


		if (x == 100 || xn == 100)//Chạm biên phải -> Xuyên qua trái //11
		{
			x = 11;
			xn = x + 1;
			me_x[0] = x;
			con_x[0] = xn;
		}
		else if (x == 10 || xn == 10)//Chạm biên phải -> Xuyên qua trái //11
		{
			x = 99;
			xn = x - 1;
			me_x[0] = x;
			con_x[0] = xn;

		}
		if (y == 1 || yn == 1)
		{
			y = 26;
			yn = y - 1;
			me_y[0] = y;
			con_y[0] = yn;
		}
		else if (y == 27 || yn == 27)
		{
			y = 2;
			yn = y + 1;
			me_y[0] = y;
			con_y[0] = yn;
		}
		if (kt_ran_an_qua())
		{
			me_hp++;
			tao_qua();
			ve_qua();
		}
		if (kt_ran_an_hoa())
		{
			hoa += 1;
			tao_hoa();
			ve_hoa();
		}
		m.lock();
		if (kt_ran_an_vang())
		{
			vang++;
		}
		m.unlock();
		if (hoa >= 5 && ran_co_dai == false)
		{
			ve_chuot();
			if (y == y_chuot || yn == y_chuot || y == y_chuot + 1 || yn == y_chuot + 1 || y == y_chuot + 2 || yn == y_chuot + 2)
			{
				for (int i = 0; i <= 15; i++)
				{
					if (x == x_chuot + i || xn == x_chuot + i)
					{
						gem = true;
						ran_co_dai = true;
						xoa_chuot_them_hoa();
						Sleep(5000);
					}
				}
			}
		}
		if (!cnt && gem)
		{
			cnt++;
			hoa = hoa - 5;
		}
		if (ran_co_dai && ((x == x_ran_co_dai + 4 && y == y_ran_co_dai - 1) || (xn == x_ran_co_dai + 4 && yn == y_ran_co_dai - 1)) && gem == true)
		{
			gem = false;
			tien_hoa = true;

		}
		if (vang == 2)
		{
			ve_cong();
			cong = true;
			if ((me_x[0] == 99 && me_y[0] == 15) || (con_x[0] == 99 && con_y[0] == 15))
			{
				hoa = 0;
				tien_hoa = true;
			}
		}
		if (cong == true && ((me_x[0] == 99 && me_y[0] == 15) || (con_x[0] == 99 && con_y[0] == 15)|| (me_x[0] == 98 && me_y[0] == 15) || (con_x[0] == 98 && con_y[0] == 15)))
		{
			break;
		}

		Sleep(110);
	}
}