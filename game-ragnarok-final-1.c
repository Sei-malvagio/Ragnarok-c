/*
-------------------
Library nya bosssss
-------------------
*/
#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

struct Player {
    char *name;
    char *tier; //Gods //Regulator //Guard //Human
    /*something important*/
    double true_damage;
    double playerHealth;
    /*Creator of the game*/
    bool isCreator;
    /*Potion*/
    int ramuan_maladewa; // 3.50
    int ramuan_regulator; //50.000
    int ramuan_guard; // 30.000
    int ramuan_felicis;
    int ramuan_amortentia;
    int ramuan_death;
    /*Rezeki*/
    double rezeki;
};

struct swords {
    char *nama_pedang;
    char *tier_pedang;
    double damage_pedang;
    /*Inventory save*/
    int demondweller__;
    int keyblade__;
    int bladeofchaos__;
    int energysword__;
    int rebellion__;
    int pemusnah_segalanya;
    /*Damage*/
    int dmg_demondweller__; //500
    int dmg_keyblade__; //50000
    int dmg_bladeofchaos__; //100.000
    int dmg_energysword__; //200
    int dmg_rebellion__; //3000
    int dmg_pemusnah_segalanya; //infinity
};

struct monster {
    char *monster_malheim; //h 200
    char *monster_surgawi; //h 1.000
    char *monster_semesta; //h 30.000
    char *raja_monster; //h 100.000
    /*health*/
    int m_surgawi;
    int m_semesta;
    int m_raja_monster;
    int m_malheim;
    int t_kills1, t_kills2, t_kills3;
};

int doubleToint_ = 0.5 * 1000; //var type global* 1000, males didalem int, nnti error
char buyone[50] = "";
char monsterName[50] = "";
char pedangNameEquip[50] = "";
char menu_utama[40] = "Ketik yes untuk kembali ke menu utama: ";
char kembali[3] = "yes";
const char *game_version = "V1.0.0";
char nama_karakter_[100] = "";

void info_tier(char *tierGods, char *tierRegulator, char *tierGuard, char *tierHuman) {
    strcpy(tierGods, " (1). Seperti yang kamu dengar, Gods. Tier Gods yang berarti Tuhan adalah tier tertinggi yang dimiliki\noleh seseorang yang mampu mendapatkan tier tsb. Tier itu memiliki\nkekuatan yang sangat amat dasyat, sehingga alam semesta kecil baginya.\nkekuatan yang terbuka ditier ini adalah sang Creator atau sang Pencipta.");
    strcpy(tierRegulator, " (2). Tier Regulator adalah tier sang pengatur, Atau bisa juga disebut sang pengatur hukum semesta dan hukum alam.\nTier ini membuka kekuatan The Ruler of the Universe!, atau bisa disebut sang pengatur semua hukum semesta.");
    strcpy(tierGuard, " (3). Tier Guard adalah tier sang penjaga, Bisa juga kita sebut sang penjaga dunia bawah.\nKarena tier Regulator tidak membutuhkan tier Guard untuk menjaga keamanan galaxy.\ndan juga tier Guard ini menjaga dunia bawah atau yg kita biasa sebut yaitu neraka.\nTier ini membuka kekuatan Guardian of the underworld!, Dalam arti sang penjaga dunia bawah!.");
    strcpy(tierHuman, " (4). Tier Human pasti kalian tahu!, tier ini hanyalah manusia biasa yang sehari-hari hanya bisa gamonin mantan, apa lagi yg gabisa move on, kesian deh wkwkwk.\nTier ini membuka kekuatan berpedang yang lumayan terlatih.");
}

void game_tutorial(const char *tutor_msg, const char *game_version) {
    game_version = "V1.0.0";
    sprintf(tutor_msg, "\n\n-------------------------\n\nTutorial penting untuk memainkan game ragnarok %s.\nPertama-tama kalian akan mendapatkan uang sebesar Rp 1.000, nah uang itu kalian manfaatkan untuk membeli pedang energy sword.\nCara membeli pedang energy sword cukup ketik shop dimenu utama, dan yang paling penting di game ini adalah cara memasukkan keyword atau penulisan ketika\nkamu ingin membeli sesuatu. Nah jika sudah masuk halaman shop, kamu akan melihat tipe sword dan tipe ramuan, untuk sementara tipe ramuan tidak bekerja karena\nsaya terhalang waktu sekolah, next update bakal bekerja ya guys. Nah terus kamu lihat ada beberapa jenis pedang, lalu kamu pilih energy sword,\njika kamu sudah membeli energy sword, kamu kembali kemenu awal dan ketik attack untuk melawan monster. Karena kamu new player, kamu direkomendasikan untuk melawan monster malheim terlebih dahulu,\nkarena darah monster tersebut hanya 200%% sama dengan damage energy swordmu!. sampai disitu kamu harus ngerti ya!. Intinya ketika kamu ingin memilih sesuatu atau membeli sesuatu, kamu cukup ketik nama yang sudah tertera disitu,\ntenang aja game ini support spasi kok kalau mau memasukkan sesuatu, sekian thank you.\n\n-------------------------\n", game_version);
}

void ketik(int *ts_1, int *ts_2, int *ts_3, int *ts_4, int *ts_5, int *ts_6) {
    *ts_1 = 700000; //70000ms
    *ts_2 = 60000; //60000ms
    *ts_3 = 50000; //50000ms
    *ts_4 = 40000; //40000ms
    *ts_5 = 30000; //30000ms
    *ts_6 = 20000; //20000ms
}


void potion_dmg(double *r_gila, double *r_maladewa, double *r_regulator, double *r_guard, int *r_felicis, int *r_amortentia, int *r_malvigo, double *r_death) {
    *r_gila = 200;
    *r_maladewa = 1.000;
    *r_regulator = 30.000;
    *r_guard = 15.000;
    *r_felicis = 500; //health potion
    *r_amortentia = 2000; //health potion
    *r_death = 100.000;
}

void jenis_sword(char* demon, char *keyblade_x, char* b_o_c, char* energy_sword, char* rebellion) {
    strcpy(demon, "Demon-Dweller"); //500
    strcpy(keyblade_x, "Keyblade"); //30.000
    strcpy(b_o_c, "Blade of Chaos"); //100.000
    strcpy(energy_sword, "Energy Sword"); //500
    strcpy(rebellion, "Rebellion"); //1.000
}

void buyItems(struct Player *pemain, struct swords *pedang, double price, const char *nameItems, const char *saveInv) {
    sleep(1);
    if(strcasecmp(buyone, "energy sword") == 0 || strcasecmp(buyone, "demon-dweller") == 0) {
        if(pemain->rezeki >= price) {
            pemain->rezeki -= price;
            printf("\n[√] Berhasil membeli %s! seharga %d\n", nameItems, doubleToint_);
            printf("\n[?] %s", menu_utama);
            scanf(" %s", kembali);
        } else {
            usleep(70000);
            printf("\n[!] Uang anda tersisa %.3lf, tidak cukup untuk membeli %s\n", pemain->rezeki, nameItems);
            printf("\n[?] %s", menu_utama);
            scanf(" %s", kembali);
        }
    }
    sleep(1);
    if(strcasecmp(buyone, "energy sword") != '\0' && strcasecmp(buyone, "demon-dweller") != '\0') {
        if(pemain->rezeki >= price) {
            pemain->rezeki -= price;
            printf("\n[√] Berhasil membeli %s! seharga %.3lf\n", nameItems, price);
            printf("\n[?] %s", menu_utama);
            scanf(" %s", kembali);
        } else {
            usleep(70000);
            printf("\n[!] Uang anda tersisa %.3lf, tidak cukup untuk membeli %s\n", pemain->rezeki, nameItems);
            printf("\n[?] %s", menu_utama);
            scanf(" %s", kembali);
        }
    }

    if(strcasecmp(buyone, "maladewa") == 0) {
        if(pemain->rezeki >= price) {
            pemain->ramuan_maladewa += 1;
        }
    } else if(strcasecmp(buyone, "regulator") == 0) {
        if(pemain->rezeki >= price) {
            pemain->ramuan_regulator += 1;
        }
    } else if(strcasecmp(buyone, "guard") == 0) {
        if(pemain->rezeki >= price) {
            pemain->ramuan_guard += 1;
        }
    } else if(strcasecmp(buyone, "felicis") == 0) {
        if(pemain->rezeki >= price) {
            pemain->ramuan_felicis += 1;
        }
    } else if(strcasecmp(buyone, "amortentia") == 0) {
        if(pemain->rezeki >= price) {
            pemain->ramuan_amortentia += 1;
        }
    } else if(strcasecmp(buyone, "death") == 0) {
        if(pemain->rezeki >= price) {
            pemain->ramuan_death += 1;
        }
    } else if(strcasecmp(buyone, "energy sword") == 0) {
        if(pemain->rezeki >= price) {
            pedang->energysword__ += 1;
        }
    } else if(strcasecmp(buyone, "demond-weller") == 0) {
        if(pemain->rezeki >= price) {
            pedang->demondweller__ += 1;
        }
    } else if(strcasecmp(buyone, "blade of chaos") == 0) {
        if(pemain->rezeki >= price) {
            pedang->bladeofchaos__ += 1;
        }
    } else if(strcasecmp(buyone, "rebellion") == 0) {
        if(pemain->rezeki >= price) {
            pedang->rebellion__ += 1;
        }
    } else if(strcasecmp(buyone, "keyblade") == 0) {
        if(pemain->rezeki >= price) {
            pedang->keyblade__ += 1;
        }
    } else {
        printf("\n[!] Pilihan untuk %s tidak tersedia", buyone);
    }
    usleep(90000);
}

void nama_pedang_(struct swords *pedang, const char *namaPedang) {
    char demon[20], keyblade_x[20], b_o_c[20], energy_sword[20], rebellion[20];
    jenis_sword(demon, keyblade_x, b_o_c, energy_sword, rebellion);
    if(strcasecmp(namaPedang, "demondweller") == 0) {
        pedang->nama_pedang = strdup(demon);
    } else if(strcasecmp(namaPedang, "energysword") == 0) {
        pedang->nama_pedang = strdup(energy_sword);
    } else if(strcasecmp(namaPedang, "keyblade") == 0) {
        pedang->nama_pedang = strdup(keyblade_x);
    } else if(strcasecmp(namaPedang, "bladeofchaos") == 0) {
        pedang->nama_pedang = strdup(b_o_c);
    } else if(strcasecmp(namaPedang, "rebellion") == 0) {
        pedang->nama_pedang = strdup(rebellion);
    } else {
        fprintf(stdout, "[!] Nama pedang tidak ditemukan!");
        return;
    }
}

void equip_items(struct swords *pedang, const char *pedangNameAndSave_inv) {
    char demon[20], keyblade_x[20], b_o_c[20], energy_sword[20], rebellion[20];
    jenis_sword(demon, keyblade_x, b_o_c, energy_sword, rebellion);


    if(strcasecmp(pedangNameAndSave_inv, "energy sword") == 0) {
        pedang->nama_pedang = strdup(energy_sword);
        sleep(1);
        fprintf(stdout, "\n[+] Berhasil memakai pedang %s!\n\n", pedangNameAndSave_inv);
        sleep(1);
        printf("[?] %s", menu_utama);
        scanf(" %s", kembali);
        sleep(1);
        return;
    } else if(strcasecmp(pedangNameAndSave_inv, "keyblade") == 0) {
        pedang->nama_pedang = strdup(keyblade_x);
        sleep(1);
        fprintf(stdout, "\n[+] Berhasil memakai pedang %s!\n\n", pedangNameAndSave_inv);
        sleep(1);
        printf("[?] %s", menu_utama);
        scanf(" %s", kembali);
        return;
    } else if(strcasecmp(pedangNameAndSave_inv, "blade of chaos") == 0) {
        pedang->nama_pedang = strdup(b_o_c);
        sleep(1);
        fprintf(stdout, "\n[+] Berhasil memakai pedang %s!\n\n", pedangNameAndSave_inv);
        sleep(1);
        printf("[?] %s", menu_utama);
        scanf(" %s", kembali);
        return;
    } else if(strcasecmp(pedangNameAndSave_inv, "rebellion") == 0) {
        pedang->nama_pedang = strdup(rebellion);
        sleep(1);
        fprintf(stdout, "\n[+] Berhasil memakai pedang %s!\n\n", pedangNameAndSave_inv);
        sleep(1);
        printf("[?] %s", menu_utama);
        scanf(" %s", kembali);
        return;
    } else if(strcasecmp(pedangNameAndSave_inv, "demon-dweller") == 0) {
        pedang->nama_pedang = strdup(demon);
        sleep(1);
        fprintf(stdout, "\n[+] Berhasil memakai pedang %s!\n\n", pedangNameAndSave_inv);
        sleep(1);
        printf("[?] %s", menu_utama);
        scanf(" %s", kembali);
        return;
    } else {
        fprintf(stdout, "\n[!] Nama pedang tidak ditemukan!");
        return;
    }
}

void attack_monster(struct swords *pedang, struct Player *pemain, struct monster *musuh, const char *monsterName_) {
    /*Inventory cek ad g*/
    int inventoryCek;

    char inventoryCek_[20];
    char msgWhoHaveSword[100];
    char choose_sword[20]; //pemilihan pedang
    char demon[15], keyblade_x[15], b_o_c[15], energy_sword[16], rebellion[15];
    /*health sementara*/
    int h_monster;

    jenis_sword(demon, keyblade_x, b_o_c, energy_sword, rebellion);

    char ngetik[200] = "\n----------------------------\n";

    if(strcasecmp(pedang->nama_pedang, "Belum memiliki") == 0) {
        printf("\n[-] Maaf kamu belum equip pedang apapun ditanganmu, silahkan equiphterlebih dahulu.");
        printf("\n\n[?] %s", menu_utama);
        scanf(" %s", kembali);
        sleep(1);
        return;
    } else if(strcasecmp(pedang->nama_pedang, "Blade of chaos") == 0) {
        pedang->nama_pedang = strdup(b_o_c);
        sprintf(msgWhoHaveSword, "[+] Kamu memakai pedang %s di tanganmu!", pedang->nama_pedang);
    } else if(strcasecmp(pedang->nama_pedang, "Energy sword") == 0) {
        pedang->nama_pedang = strdup(energy_sword);
        sprintf(msgWhoHaveSword, "[+] Kamu memakai pedang %s di tanganmu!", pedang->nama_pedang);
    } else if(strcasecmp(pedang->nama_pedang, "Demon-Dweller") == 0) {
        pedang->nama_pedang = strdup(demon);
        sprintf(msgWhoHaveSword, "[+] Kamu memakai pedang %s di tanganmu!", pedang->nama_pedang);
    } else if(strcasecmp(pedang->nama_pedang, "Keyblade") == 0) {
        pedang->nama_pedang = strdup(keyblade_x);
        sprintf(msgWhoHaveSword, "[+] Kamu memakai pedang %s di tanganmu!", pedang->nama_pedang);
    } else if(strcasecmp(pedang->nama_pedang, "Rebellion") == 0) {
        pedang->nama_pedang = strdup(rebellion);
        sprintf(msgWhoHaveSword, "[+] Kamu memakai pedang %s di tanganmu!", pedang->nama_pedang);
    } else if(strcasecmp(pedang->nama_pedang, "pemusnah segalanya") == 0) {
        sprintf(msgWhoHaveSword, "[+] Kamu memakai pedang %s di tanganmu!", pedang->nama_pedang);
    } else {
        printf("\n[!] System error: pedang invalid");
        return;
    }

    if(strcasecmp(monsterName_, "surgawi") == 0) {
        h_monster = musuh->m_surgawi;
    } else if(strcasecmp(monsterName_, "malheim") == 0) {
        h_monster = musuh->m_malheim;
    } else if(strcasecmp(monsterName_, "semesta") == 0) {
        h_monster = musuh->m_semesta;
    } else if(strcasecmp(monsterName_, "King of monsters") == 0) {
        h_monster = musuh->m_raja_monster;
    } else {
        printf("\n[!] System error: nama monster invalid");
        return;
    }

    if(strcasecmp(monsterName_, monsterName_) == 0) {
        sleep(2);
        for(int i = 0; ngetik[i] != '\0'; i++) {
            printf("%c", ngetik[i]);
            fflush(stdout);
            usleep(30000);
        }
        sleep(1);
        printf("\n[+] Kamu ingin menyerang monster %s\n\n", monsterName_);
        printf("[!] Monster health %d%%\n\n", h_monster);
        printf("%s%s\n", msgWhoHaveSword, inventoryCek_);
        for(int i = 0; ngetik[i] != '\0'; i++) {
            printf("%c", ngetik[i]);
            fflush(stdout);
            usleep(30000);
        }
        printf("\n[?] INGIN MEMAKAINYA? ya/tidak: ");
        scanf(" %s", choose_sword);
    }

    /*Memilih pedang*/
    if(strcasecmp(pedang->nama_pedang, "energy sword") == 0) {
        if(strcasecmp(choose_sword, "ya") == 0) {
            sleep(2);
            printf("\n[+] Kamu memilih pedang %s, dengan damage %d%%\n", pedang->nama_pedang, pedang->dmg_energysword__);
            for(int i = 0; ngetik[i] != '\0'; i++) {
                printf("%c", ngetik[i]);
                fflush(stdout);
                usleep(30000);
            }
            printf("\n[!] Memulai serangan ke-arah monster %s!\n\n", monsterName_);
            sleep(3);
            printf("[!] Damage yang diberikan sebesar %d%%\n\n", pedang->dmg_energysword__);
            sleep(2);
            printf("[>] Menyerang monster dengan jurus pedang %s!\n", pedang->nama_pedang);
            for(int i = 0; ngetik[i] != '\0'; i++) {
                printf("%c", ngetik[i]);
                fflush(stdout);
                usleep(30000);
            }
            if(pedang->dmg_energysword__ < h_monster) {
                sleep(3);
                printf("\n[!] OHHH TIDAK!, MONSTER INI TERLALU KUAT!\n\n");
                sleep(2);
                printf("[>] Maaf... aku terlalu ceroboh\n\n");
                sleep(2);
                printf("[>] Apakah ajalku sampai disini saja?...\n\n");
                sleep(2);
                printf("[>] Aku menyayangi kalian teman-temanku\n\n");
                sleep(2);
                printf("[>] Goodbye semuanya...\n");
            } else if(pedang->dmg_energysword__ >= h_monster) {
                sleep(3);
                printf("\n[!] HAHA!, Monster apa ini? Lemah sekali cuih\n\n");
                sleep(2);
                printf("[>] Aku akan menyerangnya dengan jurus andalanku\n\n");
                sleep(2);
                printf("[>] %s! SERANGGGGGG!!\n\n", pedang->nama_pedang);
                sleep(2);
                printf("[>] Huhh, terasa lelah sekali aku memakai jurus tersebut\n\n");
                sleep(2);
                printf("[>] Tetapi... akhirnya aku MENANG!\n");
                for(int i = 0; ngetik[i] != '\0'; i++) {
                    printf("%c", ngetik[i]);
                    fflush(stdout);
                    usleep(30000);
                }
                sleep(3);
            }
            if(pedang->dmg_energysword__ >= h_monster) {
                h_monster -= pedang->dmg_energysword__;
                h_monster = (h_monster < 0) ? 0:h_monster;
                srand(time(0)); //ngecek nmor klo dijlnin lg biar g sama
                double attackResult = ((double)rand() / RAND_MAX) * (0.5 - 1.5) + 1.5;
                pemain->rezeki += attackResult;
                printf("\n[√] VICTORY!!\n\n[>] Kamu memberi damage sebesar %d%% ke monster %s!\n\n[>] Health monster %s tersisa: %d%%\n", pedang->dmg_energysword__, monsterName_, monsterName_, h_monster);
                printf("\n[+] Hasil pendapatan uang Rp %.3lf ditambahkan!\n", attackResult);
                for(int i = 0; ngetik[i] != '\0'; i++) {
                    printf("%c", ngetik[i]);
                    fflush(stdout);
                    usleep(30000);
                }
                printf("\n[?] %s", menu_utama);
                scanf(" %s", kembali);
            } else {
                h_monster -= pedang->dmg_energysword__;
                h_monster = (h_monster < 0) ? 0:h_monster;
                srand(time(0)); //ngecek nmor klo dijlnin lg biar g sama
                double attackResult = ((double)rand() / RAND_MAX) * (0.5  - 1.5) + 1.5;
                pemain->rezeki -= attackResult;
                printf("\n[X] DEFEAT!!\n\n[>] Kamu memberi damage sebesar %d%% ke mosnter %s!\n\n[>] Health monster %s tersisa: %d%%\n", pedang->dmg_energysword__, monsterName_, monsterName_, h_monster);
                printf("\n[-] Hasil pengurangan uang sebesar Rp %.3lf dikarenakan kalah dari monster tersebut!\n", attackResult);
                for(int i = 0; ngetik[i] != '\0'; i++) {
                    printf("%c", ngetik[i]);
                    fflush(stdout);
                    usleep(30000);
                }
                printf("\n[?] %s", menu_utama);
                scanf(" %s", kembali);
            }
        } else {
            printf("\n[>] Kamu tidak ingin memakainya maka akan kembali ke menu utama\n");
            sleep(2);
            return;
        }
    } else if(strcasecmp(pedang->nama_pedang, "demon-dweller") == 0) {
        if(strcasecmp(choose_sword, "ya") == 0) {
            sleep(2);
            printf("\n[+] Kamu memilih pedang %s, dengan damage %d%%\n", pedang->nama_pedang, pedang->dmg_demondweller__);
            for(int i = 0; ngetik[i] != '\0'; i++) {
                printf("%c", ngetik[i]);
                fflush(stdout);
                usleep(30000);
            }
            printf("\n[!] Memulai serangan ke-arah monster %s!\n\n", monsterName_);
            sleep(3);
            printf("[!] Damage yang diberikan sebesar %d%%\n\n", pedang->dmg_demondweller__);
            sleep(2);
            printf("[>] Menyerang monster dengan jurus pedang %s!\n", pedang->nama_pedang);
            for(int i = 0; ngetik[i] != '\0'; i++) {
                printf("%c", ngetik[i]);
                fflush(stdout);
                usleep(30000);
            }
            if(pedang->dmg_demondweller__ < h_monster) {
                sleep(3);
                printf("\n[!] OHHH TIDAK!, MONSTER INI TERLALU KUAT!\n\n");
                sleep(2);
                printf("[>] Maaf... aku terlalu ceroboh\n\n");
                sleep(2);
                printf("[>] Apakah ajalku sampai disini saja?...\n\n");
                sleep(2);
                printf("[>] Aku menyayangi kalian teman-temanku\n\n");
                sleep(2);
                printf("[>] Goodbye semuanya...\n");
            } else if(pedang->dmg_demondweller__ >= h_monster) {
                sleep(3);
                printf("\n[!] HAHA!, Monster apa ini? Lemah sekali cuih\n\n");
                sleep(2);
                printf("[>] Aku akan menyerangnya dengan jurus andalanku\n\n");
                sleep(2);
                printf("[>] %s! SERANGGGGGG!!\n\n", pedang->nama_pedang);
                sleep(2);
                printf("[>] Huhh, terasa lelah sekali aku memakai jurus tersebut\n\n");
                sleep(2);
                printf("[>] Tetapi... akhirnya aku MENANG!\n");
                for(int i = 0; ngetik[i] != '\0'; i++) {
                    printf("%c", ngetik[i]);
                    fflush(stdout);
                    usleep(30000);
                }
                sleep(3);
            }
            if(pedang->dmg_demondweller__ >= h_monster) {
                h_monster -= pedang->dmg_demondweller__;
                h_monster = (h_monster < 0) ? 0:h_monster;
                srand(time(0)); //ngecek nmor klo dijlnin lg biar g sama
                double attackResult = ((double)rand() / RAND_MAX) * (1.5  - 2.5) + 2.5;
                pemain->rezeki += attackResult;
                printf("\n[√] VICTORY!!\n\n[>] Kamu memberi damage sebesar %d%% ke monster %s!\n\n[>] Health monster %s tersisa: %d%%\n", pedang->dmg_demondweller__, monsterName_, monsterName_, h_monster);
                printf("\n[+] Hasil pendapatan uang Rp %.3lf ditambahkan!\n", attackResult);
                for(int i = 0; ngetik[i] != '\0'; i++) {
                    printf("%c", ngetik[i]);
                    fflush(stdout);
                    usleep(30000);
                }
                printf("\n[?] %s", menu_utama);
                scanf(" %s", kembali);
            } else {
                h_monster -= pedang->dmg_demondweller__;
                h_monster = (h_monster < 0) ? 0:h_monster;
                srand(time(0)); //ngecek nmor klo dijlnin lg biar g sama
                double attackResult = ((double)rand() / RAND_MAX) * (1.5 - 2.5) + 2.5;
                pemain->rezeki -= attackResult;
                printf("\n[X] DEFEAT!!\n\n[>] Kamu memberi damage sebesar %d%% ke mosnter %s!\n\n[>] Health monster %s tersisa: %d%%\n", pedang->dmg_demondweller__, monsterName_, monsterName_, h_monster);
                printf("\n[-] Hasil pengurangan uang sebesar Rp %.3lf dikarenakan kalah dari monster tersebut!\n", attackResult);
                for(int i = 0; ngetik[i] != '\0'; i++) {
                    printf("%c", ngetik[i]);
                    fflush(stdout);
                    usleep(30000);
                }
                printf("\n[?] %s", menu_utama);
                scanf(" %s", kembali);
            }
        } else {
            printf("\n[>] Kamu tidak ingin memakainya maka akan kembali ke menu utama\n");
            sleep(2);
            return;
        }
    } else if(strcasecmp(pedang->nama_pedang, "blade of chaos") == 0) {
        if(strcasecmp(choose_sword, "ya") == 0) {
            sleep(2);
            printf("\n[+] Kamu memilih pedang %s, dengan damage %d%%\n", pedang->nama_pedang, pedang->dmg_bladeofchaos__);
            for(int i = 0; ngetik[i] != '\0'; i++) {
                printf("%c", ngetik[i]);
                fflush(stdout);
                usleep(30000);
            }
            printf("\n[!] Memulai serangan ke-arah monster %s!\n\n", monsterName_);
            sleep(3);
            printf("[!] Damage yang diberikan sebesar %d%%\n\n", pedang->dmg_bladeofchaos__);
            sleep(2);
            printf("[>] Menyerang monster dengan jurus pedang %s!\n", pedang->nama_pedang);
            for(int i = 0; ngetik[i] != '\0'; i++) {
                printf("%c", ngetik[i]);
                fflush(stdout);
                usleep(30000);
            }
            if(pedang->dmg_bladeofchaos__ < h_monster) {
                sleep(3);
                printf("\n[!] OHHH TIDAK!, MONSTER INI TERLALU KUAT!\n\n");
                sleep(2);
                printf("[>] Maaf... aku terlalu ceroboh\n\n");
                sleep(2);
                printf("[>] Apakah ajalku sampai disini saja?...\n\n");
                sleep(2);
                printf("[>] Aku menyayangi kalian teman-temanku\n\n");
                sleep(2);
                printf("[>] Goodbye semuanya...\n");
            } else if(pedang->dmg_bladeofchaos__ >= h_monster) {
                sleep(3);
                printf("\n[!] HAHA!, Monster apa ini? Lemah sekali cuih\n\n");
                sleep(2);
                printf("[>] Aku akan menyerangnya dengan jurus andalanku\n\n");
                sleep(2);
                printf("[>] %s! SERANGGGGGG!!\n\n", pedang->nama_pedang);
                sleep(2);
                printf("[>] Huhh, terasa lelah sekali aku memakai jurus tersebut\n\n");
                sleep(2);
                printf("[>] Tetapi... akhirnya aku MENANG!\n");
                for(int i = 0; ngetik[i] != '\0'; i++) {
                    printf("%c", ngetik[i]);
                    fflush(stdout);
                    usleep(30000);
                }
                sleep(3);
            }
            if(pedang->dmg_bladeofchaos__ >= h_monster) {
                h_monster -= pedang->dmg_bladeofchaos__;
                h_monster = (h_monster < 0) ? 0:h_monster;
                srand(time(0)); //ngecek nmor klo dijlnin lg biar g sama
                double attackResult = ((double)rand() / RAND_MAX) * (4.0 - 5.0) + 4.0;
                pemain->rezeki += attackResult;
                printf("\n[√] VICTORY!!\n\n[>] Kamu memberi damage sebesar %d%% ke monster %s!\n\n[>] Health monster %s tersisa: %d%%\n", pedang->dmg_bladeofchaos__, monsterName_, monsterName_, h_monster);
                printf("\n[+] Hasil pendapatan uang Rp %.3lf ditambahkan!\n", attackResult);
                for(int i = 0; ngetik[i] != '\0'; i++) {
                    printf("%c", ngetik[i]);
                    fflush(stdout);
                    usleep(30000);
                }
                printf("\n[?] %s", menu_utama);
                scanf(" %s", kembali);
            } else {
                h_monster -= pedang->dmg_bladeofchaos__;
                h_monster = (h_monster < 0) ? 0:h_monster;
                srand(time(0)); //ngecek nmor klo dijlnin lg biar g sama
                double attackResult = ((double)rand() / RAND_MAX) * (4.0  - 5.0) + 5.0;
                pemain->rezeki -= attackResult;
                printf("\n[X] DEFEAT!!\n\n[>] Kamu memberi damage sebesar %d%% ke mosnter %s!\n\n[>] Health monster %s tersisa: %d%%\n", pedang->dmg_bladeofchaos__, monsterName_, monsterName_, h_monster);
                printf("\n[-] Hasil pengurangan uang sebesar Rp %.3lf dikarenakan kalah dari monster tersebut!\n", attackResult);
                for(int i = 0; ngetik[i] != '\0'; i++) {
                    printf("%c", ngetik[i]);
                    fflush(stdout);
                    usleep(30000);
                }
                printf("\n[?] %s", menu_utama);
                scanf(" %s", kembali);
            }
        } else {
            printf("\n[>] Kamu tidak ingin memakainya maka akan kembali ke menu utama\n");
            sleep(2);
            return;
        }
    } else if(strcasecmp(pedang->nama_pedang, "keyblade") == 0) {
        if(strcasecmp(choose_sword, "ya") == 0) {
            sleep(2);
            printf("\n[+] Kamu memilih pedang %s, dengan damage %d%%\n", pedang->nama_pedang, pedang->dmg_keyblade__);
            for(int i = 0; ngetik[i] != '\0'; i++) {
                printf("%c", ngetik[i]);
                fflush(stdout);
                usleep(30000);
            }
            printf("\n[!] Memulai serangan ke-arah monster %s!\n\n", monsterName_);
            sleep(3);
            printf("[!] Damage yang diberikan sebesar %d%%\n\n", pedang->dmg_keyblade__);
            sleep(2);
            printf("[>] Menyerang monster dengan jurus pedang %s!\n", pedang->nama_pedang);
            for(int i = 0; ngetik[i] != '\0'; i++) {
                printf("%c", ngetik[i]);
                fflush(stdout);
                usleep(30000);
            }
            if(pedang->dmg_keyblade__ < h_monster) {
                sleep(3);
                printf("\n[!] OHHH TIDAK!, MONSTER INI TERLALU KUAT!\n\n");
                sleep(2);
                printf("[>] Maaf... aku terlalu ceroboh\n\n");
                sleep(2);
                printf("[>] Apakah ajalku sampai disini saja?...\n\n");
                sleep(2);
                printf("[>] Aku menyayangi kalian teman-temanku\n\n");
                sleep(2);
                printf("[>] Goodbye semuanya...\n");
            } else if(pedang->dmg_keyblade__ >= h_monster) {
                sleep(3);
                printf("\n[!] HAHA!, Monster apa ini? Lemah sekali cuih\n\n");
                sleep(2);
                printf("[>] Aku akan menyerangnya dengan jurus andalanku\n\n");
                sleep(2);
                printf("[>] %s! SERANGGGGGG!!\n\n", pedang->nama_pedang);
                sleep(2);
                printf("[>] Huhh, terasa lelah sekali aku memakai jurus tersebut\n\n");
                sleep(2);
                printf("[>] Tetapi... akhirnya aku MENANG!\n");
                for(int i = 0; ngetik[i] != '\0'; i++) {
                    printf("%c", ngetik[i]);
                    fflush(stdout);
                    usleep(30000);
                }
                sleep(3);
            }
            if(pedang->dmg_keyblade__ >= h_monster) {
                h_monster -= pedang->dmg_keyblade__;
                h_monster = (h_monster < 0) ? 0:h_monster;
                srand(time(0)); //ngecek nmor klo dijlnin lg biar g sama
                double attackResult = ((double)rand() / RAND_MAX) * (3.0  - 4.0) + 4.0;
                pemain->rezeki += attackResult;
                printf("\n[√] VICTORY!!\n\n[>] Kamu memberi damage sebesar %d%% ke monster %s!\n\n[>] Health monster %s tersisa: %d%%\n", pedang->dmg_keyblade__, monsterName_, monsterName_, h_monster);
                printf("\n[+] Hasil pendapatan uang Rp %.3lf ditambahkan!\n", attackResult);
                for(int i = 0; ngetik[i] != '\0'; i++) {
                    printf("%c", ngetik[i]);
                    fflush(stdout);
                    usleep(30000);
                }
                printf("\n[?] %s", menu_utama);
                scanf(" %s", kembali);
            } else {
                h_monster -= pedang->dmg_keyblade__;
                h_monster = (h_monster < 0) ? 0:h_monster;
                srand(time(0)); //ngecek nmor klo dijlnin lg biar g sama
                double attackResult = ((double)rand() / RAND_MAX) * (3.0  - 4.0) + 4.0;
                pemain->rezeki -= attackResult;
                printf("\n[X] DEFEAT!!\n\n[>] Kamu memberi damage sebesar %d%% ke mosnter %s!\n\n[>] Health monster %s tersisa: %d%%\n", pedang->dmg_keyblade__, monsterName_, monsterName_, h_monster);
                printf("\n[-] Hasil pengurangan uang sebesar Rp %.3lf dikarenakan kalah dari monster tersebut!\n", attackResult);
                for(int i = 0; ngetik[i] != '\0'; i++) {
                    printf("%c", ngetik[i]);
                    fflush(stdout);
                    usleep(30000);
                }
                printf("\n[?] %s", menu_utama);
                scanf(" %s", kembali);
            }
        } else {
            printf("\n[>] Kamu tidak ingin memakainya maka akan kembali ke menu utama\n");
            sleep(2);
            return;
        }
    } else if(strcasecmp(pedang->nama_pedang, "rebellion") == 0) {
        if(strcasecmp(choose_sword, "ya") == 0) {
            sleep(2);
            printf("\n[+] Kamu memilih pedang %s, dengan damage %d%%\n", pedang->nama_pedang, pedang->dmg_rebellion__);
            for(int i = 0; ngetik[i] != '\0'; i++) {
                printf("%c", ngetik[i]);
                fflush(stdout);
                usleep(30000);
            }
            printf("\n[!] Memulai serangan ke-arah monster %s!\n\n", monsterName_);
            sleep(3);
            printf("[!] Damage yang diberikan sebesar %d%%\n\n", pedang->dmg_rebellion__);
            sleep(2);
            printf("[>] Menyerang monster dengan jurus pedang %s!\n", pedang->nama_pedang);
            for(int i = 0; ngetik[i] != '\0'; i++) {
                printf("%c", ngetik[i]);
                fflush(stdout);
                usleep(30000);
            }
            if(pedang->dmg_rebellion__ < h_monster) {
                sleep(3);
                printf("\n[!] OHHH TIDAK!, MONSTER INI TERLALU KUAT!\n\n");
                sleep(2);
                printf("[>] Maaf... aku terlalu ceroboh\n\n");
                sleep(2);
                printf("[>] Apakah ajalku sampai disini saja?...\n\n");
                sleep(2);
                printf("[>] Aku menyayangi kalian teman-temanku\n\n");
                sleep(2);
                printf("[>] Goodbye semuanya...\n");
            } else if(pedang->dmg_rebellion__ >= h_monster) {
                sleep(3);
                printf("\n[!] HAHA!, Monster apa ini? Lemah sekali cuih\n\n");
                sleep(2);
                printf("[>] Aku akan menyerangnya dengan jurus andalanku\n\n");
                sleep(2);
                printf("[>] %s! SERANGGGGGG!!\n\n", pedang->nama_pedang);
                sleep(2);
                printf("[>] Huhh, terasa lelah sekali aku memakai jurus tersebut\n\n");
                sleep(2);
                printf("[>] Tetapi... akhirnya aku MENANG!\n");
                for(int i = 0; ngetik[i] != '\0'; i++) {
                    printf("%c", ngetik[i]);
                    fflush(stdout);
                    usleep(30000);
                }
                sleep(3);
            }
            if(pedang->dmg_rebellion__ >= h_monster) {
                h_monster -= pedang->dmg_rebellion__;
                h_monster = (h_monster < 0) ? 0:h_monster;
                srand(time(0)); //ngecek nmor klo dijlnin lg biar g sama
                double attackResult = ((double)rand() / RAND_MAX) * (3.0  - 4.0) + 4.0;
                pemain->rezeki += attackResult;
                printf("\n[√] VICTORY!!\n\n[>] Kamu memberi damage sebesar %d%% ke monster %s!\n\n[>] Health monster %s tersisa: %d%%\n", pedang->dmg_rebellion__, monsterName_, monsterName_, h_monster);
                printf("\n[+] Hasil pendapatan uang Rp %.3lf ditambahkan!\n", attackResult);
                for(int i = 0; ngetik[i] != '\0'; i++) {
                    printf("%c", ngetik[i]);
                    fflush(stdout);
                    usleep(30000);
                }
                printf("\n[?] %s", menu_utama);
                scanf(" %s", kembali);
            } else {
                h_monster -= pedang->dmg_rebellion__;
                h_monster = (h_monster < 0) ? 0:h_monster;
                srand(time(0)); //ngecek nmor klo dijlnin lg biar g sama
                double attackResult = ((double)rand() / RAND_MAX) * (3.0  - 4.0) + 4.0;
                pemain->rezeki -= attackResult;
                printf("\n[X] DEFEAT!!\n\n[>] Kamu memberi damage sebesar %d%% ke mosnter %s!\n\n[>] Health monster %s tersisa: %d%%\n", pedang->dmg_rebellion__, monsterName_, monsterName_, h_monster);
                printf("\n[-] Hasil pengurangan uang sebesar Rp %.3lf dikarenakan kalah dari monster tersebut!\n", attackResult);
                for(int i = 0; ngetik[i] != '\0'; i++) {
                    printf("%c", ngetik[i]);
                    fflush(stdout);
                    usleep(30000);
                }
                printf("\n[?] %s", menu_utama);
                scanf(" %s", kembali);
            }
        } else {
            printf("\n[>] Kamu tidak ingin memakainya maka akan kembali ke menu utama\n");
            sleep(2);
            return;
        }
    } else if(strcasecmp(pedang->nama_pedang, "Pemusnah segalanya") == 0) {
        if(strcasecmp(choose_sword, "ya") == 0) {
            sleep(2);
            printf("\n[+] Kamu memilih pedang %s, dengan damage %d%%\n", pedang->nama_pedang, pedang->dmg_pemusnah_segalanya);
            for(int i = 0; ngetik[i] != '\0'; i++) {
                printf("%c", ngetik[i]);
                fflush(stdout);
                usleep(30000);
            }
            printf("\n[!] Memulai serangan ke-arah monster %s!\n\n", monsterName_);
            sleep(3);
            printf("[!] Damage yang diberikan sebesar %d%%\n\n", pedang->dmg_pemusnah_segalanya);
            sleep(2);
            printf("[>] Menyerang monster dengan jurus pedang %s!\n", pedang->nama_pedang);
            for(int i = 0; ngetik[i] != '\0'; i++) {
                printf("%c", ngetik[i]);
                fflush(stdout);
                usleep(30000);
            }
            if(pedang->dmg_pemusnah_segalanya >= h_monster) {
                sleep(3);
                printf("\n[!] Ngelawan kok sama developer? wkwkwk\n");
                for(int i = 0; ngetik[i] != '\0'; i++) {
                    printf("%c", ngetik[i]);
                    fflush(stdout);
                    usleep(30000);
                }
                sleep(3);
            }
            if(pedang->dmg_pemusnah_segalanya >= h_monster) {
                h_monster -= pedang->dmg_pemusnah_segalanya;
                h_monster = (h_monster < 0) ? 0:h_monster;
                srand(time(0)); //ngecek nmor klo dijlnin lg biar g sama
                double attackResult = ((double)rand() / RAND_MAX) * (300.00  - 400.00) + 400.00;
                pemain->rezeki += attackResult;
                printf("\n[√] VICTORY!!\n\n[>] Kamu memberi damage sebesar %d%% ke monster %s!\n\n[>] Health monster %s tersisa: %d%%\n", pedang->dmg_pemusnah_segalanya, monsterName_, monsterName_, h_monster);
                printf("\n[+] Hasil pendapatan uang Rp %.3lf ditambahkan!\n", attackResult);
                for(int i = 0; ngetik[i] != '\0'; i++) {
                    printf("%c", ngetik[i]);
                    fflush(stdout);
                    usleep(30000);
                }
                printf("\n[?] %s", menu_utama);
                scanf(" %s", kembali);
            }
        } else {
            printf("\n[>] Kamu tidak ingin memakainya maka akan kembali ke menu utama\n");
            sleep(2);
            return;
        }
    } else {
        printf("\n[!] System error: pedang invalid");
        return;
    }
}

int main() {
    /*Call function*/
    int ts_1, ts_2, ts_3;
    int ts_4, ts_5, ts_6;
    ketik(&ts_1, &ts_2, &ts_3, &ts_4, &ts_5, &ts_6);
    char tierGods[3000], tierRegulator[3000], tierGuard[3000], tierHuman[3000];
    info_tier(tierGods, tierRegulator, tierGuard, tierHuman);
    double r_gila, r_maladewa, r_regulator, r_guard, r_death;
    int r_felix_felicis, r_malvigo, r_amortentia;
    potion_dmg(&r_gila, &r_maladewa, &r_regulator, &r_guard, &r_felix_felicis, &r_malvigo, &r_amortentia, &r_death);
    char demon[15], keyblade[15], b_o_c[15], energy_sword[15], rebellion[15];
    jenis_sword(demon, keyblade, b_o_c, energy_sword, rebellion);
    char tutor_msg[5000];
    game_tutorial(tutor_msg, game_version);

    /*Alokalisasi struct bang*/
    struct Player *pemain = (struct Player*)malloc(sizeof(struct Player));
    struct swords *pedang = (struct swords*)malloc(sizeof(struct swords));
    struct monster *musuh = (struct monster*)malloc(sizeof(struct monster));

    /*Deklarasi Player status*/
    pemain->name = nama_karakter_;
    pemain->tier = "Human";
    pemain->true_damage = 0;
    pemain->isCreator = false;
    pemain->rezeki = 1.0; //1000
    pemain->ramuan_maladewa = 0; // 3.50
    pemain->ramuan_regulator = 0; //50.000
    pemain->ramuan_guard = 0; // 30.000
    pemain->ramuan_felicis = 0;
    pemain->ramuan_amortentia = 0;
    pemain->ramuan_death = 0;

    /*Deklarasi Untuk senjata*/
    pedang->nama_pedang = "Belum memiliki";
    pedang->demondweller__ = 0;
    pedang->keyblade__ = 0;
    pedang->energysword__ = 0;
    pedang->bladeofchaos__ = 0;
    pedang->rebellion__ = 0;
    pedang->dmg_demondweller__ = 500;
    pedang->dmg_keyblade__ = 50000;
    pedang->dmg_bladeofchaos__ = 100000;
    pedang->dmg_energysword__ = 200;
    pedang->dmg_rebellion__ = 3000; //damage
    pedang->dmg_pemusnah_segalanya = 99999999;
    /*Deklarasi buat monsterny*/
    musuh->monster_malheim = "Monster Malheim"; //monster biasa
    musuh->monster_surgawi = "Monster Surgawi";
    musuh->monster_semesta = "Monster Semesta";
    musuh->raja_monster = "King of Monster";
    musuh->m_surgawi = 3000; //health
    musuh->m_semesta = 50000;
    musuh->m_raja_monster = 100000;
    musuh->m_malheim = 200;
    musuh->t_kills1 = 0;
    musuh->t_kills2 = 0;
    musuh->t_kills3 = 0;

    /*Harga pedang~~~*/
    double keyBlade_ = 6.0, blade_o_c = 20.0, rebellion_ = 1.5, energysword_ = 0.5, demon_ = 0.5;
    double maladewa_ = 1.15, guard_ = 4.5, regulator_ = 15.5, death_ = 20.0, felicis_ = 2.2, amortentia_ = 8.8;

    printf("Tulis nama karaktermu disini: ");
    scanf(" %99[^\n]", nama_karakter_);
    printf("\nBaik nama karaktermu sudah saya atur (%s)\n\n\n", pemain->name);
    sleep(1);

    /*Game developer cekkkkk~~ wkwk*/
    char *siapaGameDevDisini = "Sei malvagio dong wkwk";
    if(strcasecmp(nama_karakter_, "Sei malvagio") == 0) {
        pemain->isCreator = true;
        pemain->tier = "Developer";
        siapaGameDevDisini = "Yes!";
        pemain->true_damage = 999.999;
        pemain->rezeki = 999.999; //1000
        pemain->ramuan_maladewa = 999999; // 3.50
        pemain->ramuan_regulator = 999999; //50.000
        pemain->ramuan_guard = 999999; // 30.000
        pemain->ramuan_felicis = 999999;
        pemain->ramuan_amortentia = 999999;
        pemain->ramuan_death = 999999;
        /*Deklarasi Untuk senjata*/
        pedang->nama_pedang = "Pemusnah segalanya";
        pedang->demondweller__ = 999999;
        pedang->keyblade__ = 999999;
        pedang->energysword__ = 999999;
        pedang->bladeofchaos__ = 999999;
        pedang->rebellion__ = 999999;
        pedang->pemusnah_segalanya = 999999;
    } else {
        pemain->isCreator = false;
        siapaGameDevDisini = "No!";
    }

    /*Perawalan*/
    char ngetik[3000] = "\n---------------------------\n------------------\n\n|-| S E L M A T D A T A N G |-|\n\n[!] DI GAME PERMAINAN RAGNAROK V1 [!]\n\n[!] Creator: Sei malvagio(Jafar Sodiq) [!]\n\n[-] Genre: Fantasi [!]\n\n------------------\n---------------------------\n\n";
    for(int i = 0; ngetik[i] != '\0'; i++) {
        printf("%c", ngetik[i]);
        fflush(stdout);
        usleep(ts_6);
    }

    char ngetik_[200] = "[!] Loading source code";
    char ngetik__[200] = "...\n\n";
    char ngetik__x[200] = "[+] Source code success fully loaded ahay!\n";
    for(int i = 0; ngetik_[i] != '\0'; i++) {
        printf("%c", ngetik_[i]);
        fflush(stdout);
        usleep(ts_3);
    }

    for(int i = 0; ngetik__[i] != '\0'; i++) {
        printf("%c", ngetik__[i]);
        fflush(stdout);
        usleep(ts_1);
    }

    for(int i = 0; ngetik__x[i] != '\0'; i++) {
        printf("%c", ngetik__x[i]);
        fflush(stdout);
        usleep(ts_4);
    }

    printf("\n[+] Silahkan menikmati, dan jangan lupa baca tutorialnya ya!\n");
    /*Perawalan*/
    while(strcasecmp(kembali, "yes") == 0) {
        char choose[10] = "";
        sleep(1);
        printf("\n\n---- MENU UTAMA ----\n\n");
        printf("- Melihat status ketik: stats\n\n- Melihat total kills ketik: tkilss\n\n- Serang monster ketik: attack\n\n- Shop ketik: shop\n\n- Info tentang tier ketik: infotier\n\n- Cek inventory ketik: inv\n\n- Memakai senjata/Equip ketik: equip\n\n- Keluar game ketik: exit\n\n");
        printf("[...] Silahkan pilih: ");
        scanf(" %s", choose);

        char *overpower_ = NULL;
        if(pemain->isCreator == true) {
            overpower_ = "Creator";
        } else if(pemain->ramuan_death && pedang->bladeofchaos__) {
            overpower_ = "Ramuan Death, Pedang Blade of Chaos";
        } else if(pemain->ramuan_death) {
            overpower_ = "Ramuan Death";
        } else if(pedang->bladeofchaos__) {
            overpower_ = "Pedang Blade of Chaos";
        } else {
            overpower_ = "Belum memiliki";
        }

        /*converterrr coy*/
        char convertTochar[10];
        char convertTochar_[10];
        if(pemain->rezeki == 0) {
            sprintf(convertTochar, "%g", pemain->rezeki); //0
        } else if(pemain->rezeki >= 0) {
            sprintf(convertTochar, "%.3lf", pemain->rezeki); //1000
        } else {
            printf("[!] Gagal mengubah");
        }

        if(pemain->true_damage == 0) {
            sprintf(convertTochar_, "%g", pemain->true_damage); //1000
        } else if(pemain->true_damage >= 0) {
            sprintf(convertTochar_, "%.3lf", pemain->true_damage); //muncul
        } else {
            printf("[!] Gagal mengubah");
        }

        /*Milih yang mana*/
        if(strcasecmp(choose, "stats") == 0) {
            usleep(ts_1);
            printf("\n\n[#] STATUS KAMU [#]\n\n");
            printf("[>] Name: %s\n", pemain->name);
            printf("[>] Tier: %s\n", pemain->tier);
            printf("[>] Pedang yg dipakai: %s\n", pedang->nama_pedang);
            printf("[>] Uang: %s\n", convertTochar);
            //printf("[>] Game developer: %s\n", siapaGameDevDisini);
            printf("[!] Kekuatan Overpower : %s\n\n", overpower_);
            printf("[?] %s", menu_utama);
            scanf(" %s", kembali);
        } else if(strcasecmp(choose, "shop") == 0) {
            usleep(ts_1);
            printf("\n\n[#] SHOP [#]\n\n");
            printf("[^] TIPE SWORDS [^]\n\n");
            printf("[>] Energy sword Rp %d\n", doubleToint_);
            printf("[>] Demon-Dweller Rp %d\n", doubleToint_);
            printf("[>] Keyblade Rp %.3lf\n", keyBlade_);
            printf("[!] Blade of Chaos (+Overpower) Rp %.3lf\n", blade_o_c);
            printf("[>] Rebellion Rp %.3lf\n", rebellion_);
            printf("\n[^] TIPE RAMUAN [^]\n\n");
            printf("[>] Maladewa Rp %.3lf\n", maladewa_);
            printf("[>] Guard Rp %.3lf\n", guard_);
            printf("[>] Regulator Rp %.3lf\n", regulator_);
            printf("[>] Death (+Overpower) Rp %.3lf\n", death_);
            printf("[>] Felicis Rp %.3lf\n", felicis_);
            printf("[>] Amortentia Rp %.3lf\n\n", amortentia_);
            printf("[>] Uangmu di dompet %s\n\n", convertTochar);
            printf("[>] JIKA TIDAK INGIN MEMBELI BARANG KETIK TIDAK!\n[?] PILIH BARANG: ");
            scanf(" %49[^\n]", buyone);
            while(getchar() != '\n');
            if(strcasecmp(buyone, "energy sword") == 0) {
                buyItems(pemain, pedang, energysword_, "Energy Sword", "energysword");
            }
            if(strcasecmp(buyone, "demond-weller") == 0) {
                buyItems(pemain, pedang, demon_, "Demon-Dweller", "demondweller");
            }
            if(strcmp(buyone, "keyblade") == 0 || strcasecmp(buyone, "KeyBlade") == 0 || strcasecmp(buyone, "Keyblade") == 0 || strcasecmp(buyone, "keyBlade") == 0 || strcasecmp(buyone, "KEYBLADE") == 0) {
                buyItems(pemain, pedang, keyBlade_, "Keyblade", "keyblade");
            }
            if(strcasecmp(buyone, "Blade of chaos") == 0 || strcasecmp(buyone, "bladeofchaos") == 0 || strcasecmp(buyone, "bladeofChaos") == 0 || strcasecmp(buyone, "Bladeofchaos") == 0 || strcasecmp(buyone, "BLADEOFCHAOS") == 0) {
                buyItems(pemain, pedang, blade_o_c, "Blade of Chaos", "bladeofchaos");
            }
            if(strcasecmp(buyone, "rebellion") == 0 || strcasecmp(buyone, "Rebellion") == 0 || strcasecmp(buyone, "REBELLION") == 0 || strcasecmp(buyone, "RebellioN") == 0) {
                buyItems(pemain, pedang, rebellion_, "Rebellion", "rebellion");
            }
            if(strcasecmp(buyone, "Maladewa") == 0 || strcasecmp(buyone, "maladewa") == 0 || strcasecmp(buyone, "MalaDewa") == 0 || strcasecmp(buyone, "malaDewa") == 0 || strcasecmp(buyone, "MALADEWA") == 0) {
                buyItems(pemain, pedang, maladewa_, "Ramuan Maladewa", "maladewa");
            }
            if(strcasecmp(buyone, "Regulator") == 0 || strcasecmp(buyone, "regulator") == 0 || strcasecmp(buyone, "ReguLator") == 0 || strcasecmp(buyone, "REGULATOR") == 0 || strcasecmp(buyone, "reguLator") == 0) {
                buyItems(pemain, pedang, regulator_, "Ramuan Regulator", "regulator");
            }
            if(strcasecmp(buyone, "Guard") == 0 || strcasecmp(buyone, "guard") == 0 || strcasecmp(buyone, "guaRd") == 0 || strcasecmp(buyone, "GUARD") == 0 || strcasecmp(buyone, "GUard") == 0) {
                buyItems(pemain, pedang, guard_, "Ramuan Guard", "guard");
            }
            if(strcasecmp(buyone, "Felicis") == 0 || strcasecmp(buyone, "felicis") == 0 || strcasecmp(buyone, "FELICIS") == 0 || strcasecmp(buyone, "FElicis") == 0 || strcasecmp(buyone, "FeliciS") == 0) {
                buyItems(pemain, pedang, felicis_, "Ramuan Felicis", "felicis");
            }
            if(strcasecmp(buyone, "Amortentia") == 0 || strcasecmp(buyone, "amortentia") == 0 || strcasecmp(buyone, "AmorTentia") == 0 || strcasecmp(buyone, "AMortentia") == 0 || strcasecmp(buyone, "AMORTENTIA") == 0) {
                buyItems(pemain, pedang, amortentia_, "Ramuan Amortentia", "amortentia");
            }
            if(strcasecmp(buyone, "death") == 0) {
                buyItems(pemain, pedang, death_, "Ramuan Death", "death");
            }
        } else if(strcasecmp(choose, "attack") == 0) {
            usleep(ts_1);
            printf("\n\n[#] ATTACK THE MONSTERS [#]\n\n");
            printf("[>] Monster Malheim\n[-] Status: Easy, total health: %d%%\n\n", musuh->m_malheim);
            printf("[>] Monster Surgawi\n[-] Status: Normal, total health: %d%%\n\n", musuh->m_surgawi);
            printf("[>] Monster Semesta\n[-] Status: Hard, total health: %d%%\n\n", musuh->m_semesta);
            printf("[>] King of Monsters\n[!] Status: Extreme/Dangerous, total health: %d%%\n\n", musuh->m_raja_monster);
            printf("[>] JIKA TIDAK INGIN MELAWAN KETIK TIDAK!\n");
            printf("[?] PILIH MONSTER: ");
            scanf(" %49[^\n]", monsterName);
            while(getchar() != '\n'); //bersihij buffer cuy
            if(strcasecmp(monsterName, "monster malheim") == 0) {
                attack_monster(pedang, pemain, musuh, "malheim");
            }
            if(strcasecmp(monsterName, "monster surgawi") == 0) {
                attack_monster(pedang, pemain, musuh, "surgawi");
            }
            if(strcasecmp(monsterName, "monster semesta") == 0) {
                attack_monster(pedang, pemain, musuh, "semesta");
            }
            if(strcasecmp(monsterName, "king of monsters") == 0) {
                attack_monster(pedang, pemain, musuh, "king of monsters");
            }
        } else if(strcasecmp(choose, "tkills") == 0) {
            usleep(ts_1);
            printf("\n[#] TOTAL KIILS [#]\n\n");
            printf("[>] Monster Surgawi : %d\n", musuh->t_kills1);
            printf("[>] Monster Semesta : %d\n", musuh->t_kills2);
            printf("[>] King of Monsters : %d\n\n", musuh->t_kills3);
            printf("[?] %s", menu_utama);
            scanf(" %s", kembali);
        } else if(strcasecmp(choose, "equip") == 0) {
            usleep(ts_1);
            printf("\n\n[#] EQUIP ITEMS [#]\n\n");
            printf("[!] Blade of Chaos (+Overpower) : %d\n", pedang->bladeofchaos__);
            printf("[>] Keyblade : %d\n", pedang->keyblade__);
            printf("[>] Energy Sword : %d\n", pedang->energysword__);
            printf("[>] Rebellion : %d\n", pedang->rebellion__);
            printf("[>] Demon-Dweller : %d\n\n", pedang->demondweller__);
            printf("[?] EQUIP PEDANG: ");
            scanf(" %49[^\n]", pedangNameEquip);
            while(getchar() != '\n');

            if(pedang->bladeofchaos__ && (strcasecmp(pedangNameEquip, "blade of chaos") == 0)) {
                equip_items(pedang, "blade of chaos");
            }
            else if(pedang->keyblade__ && (strcasecmp(pedangNameEquip, "keyblade") == 0)) {
                equip_items(pedang, "keyblade");
            }
            else if(pedang->rebellion__ && (strcasecmp(pedangNameEquip, "rebellion") == 0)) {
                equip_items(pedang, "rebellion");
            }
            else if(pedang->energysword__ && (strcasecmp(pedangNameEquip, "energy sword") == 0)) {
                equip_items(pedang, "energy sword");
            }
            else if(pedang->demondweller__ && (strcasecmp(pedangNameEquip, "demon-dweller") == 0)) {
                equip_items(pedang, "demon-dweller");
            } else {
                printf("\n[!] Kamu tidak memiliki pedang %s", pedangNameEquip);
            }
        } else if(strcasecmp(choose, "inv") == 0) {
            usleep(ts_1);
            printf("\n\n[#] INVENTORY [#]\n\n");
            printf("[>] Ramuan Maladewa : %d\n", pemain->ramuan_maladewa);
            printf("[>] Ramuan Guard : %d\n", pemain->ramuan_guard);
            printf("[>] Ramuan Regulator : %d\n", pemain->ramuan_regulator);
            printf("[>] Ramuan Felicis : %d\n", pemain->ramuan_felicis);
            printf("[>] Ramuan Amortentia : %d\n", pemain->ramuan_amortentia);
            printf("[!] Ramuan Death (+Overpower) : %d\n", pemain->ramuan_death);
            printf("[!] Pedang Blade of Chaos (+Overpower) : %d\n", pedang->bladeofchaos__);
            printf("[>] Pedang Keyblade : %d\n", pedang->keyblade__);
            printf("[>] Pedang Energy Sword : %d\n", pedang->energysword__);
            printf("[>] Pedang Rebellion : %d\n", pedang->rebellion__);
            printf("[>] Pedang Demon-Dweller : %d\n\n", pedang->demondweller__);
            printf("[?] %s", menu_utama);
            scanf(" %s", kembali);
        } else if(strcasecmp(choose, "infotier") == 0) {
            sleep(1);
            ts_6 = 3000; //2500ms
            /*Untuk menggabungkan string-string cok pegel*/
            sprintf(ngetik, "\n\n%s\n\n%s\n\n%s\n\n%s\n\n", tierGods, tierRegulator, tierGuard, tierHuman);
            for(int i = 0; ngetik[i] != '\0'; i++) {
                printf("%c", ngetik[i]);
                fflush(stdout);
                usleep(ts_6);
            }
            printf("[?] %s", menu_utama);
            scanf(" %s", kembali);
        } else if(strcasecmp(choose, "tutorial") == 0) {
            sleep(1);
            sprintf(ngetik, "%s", tutor_msg);
            for(int i = 0; ngetik[i] != '\0'; i++) {
                printf("%c", ngetik[i]);
                fflush(stdout);
                usleep(8000);
            }
            printf("[?] %s", menu_utama);
            scanf(" %s", kembali);
        } else if(strcasecmp(choose, "exit") == 0) {
            sleep(2);
            exit(1);
        } else {
            printf("\n[!] Pilihan untuk %s tidak tersedia", choose);
        }

    }

}