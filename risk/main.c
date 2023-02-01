#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_ttf.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define black al_map_rgb(0 , 0 , 0)
#define red al_map_rgb(255 , 0 , 0)
#define darkred al_map_rgb(139 , 0 , 0)
#define yellow al_map_rgb(255 , 255 , 0)
#define green al_map_rgb(0 , 255 , 0)
#define blue al_map_rgb(0 , 0 , 255)
#define skyblue al_map_rgb(0,191,255)
#define white al_map_rgb(255,255,255)
#define deeppink al_map_rgb(255,20,147)
#define darkgreen al_map_rgb(0,100,0)
#define aqua al_map_rgb(0,255,255)
#define purple al_map_rgb(128,0,128)
#define chocolate al_map_rgb(210,105,30)
#define aqua_marine al_map_rgb(127,255,212)
#define moccasin al_map_rgb(255,228,181)

ALLEGRO_FONT *font;

int sarzaminha[29][2]={ {0,0},
                        {0,1},
                        {0,2},
                        {0,3},
                        {0,4},
                        {0,5},
                        {1,0},
                        {1,1},
                        {1,5},

                        {2,0},
                       {2,1},
                       {2,2},
                       {3,0},
                       {3,1},
                       {3,2},

                       {4,0},
                       {4,1},
                       {4,2},
                       {4,3},
                       {5,0},
                       {5,1},
                       {5,2},
                       {5,3},

                       {2,4},
                       {2,5},
                       {2,6},
                       {3,3},
                       {3,4},
                       {3,5}};

int sarzamin_USA[9][2] ={{0,0},
                         {0,1},
                         {0,2},
                         {0,3},
                         {0,4},
                         {0,5},
                         {1,0},
                         {1,1},
                         {1,5}};

int sarzamin_Europe[6][2] ={{2,0},
                           {2,1},
                           {2,2},
                           {3,0},
                           {3,1},
                           {3,2}};

int sarzamin_Asia[8][2]  ={{4,0},
                           {4,1},
                           {4,2},
                           {4,3},
                           {5,0},
                           {5,1},
                           {5,2},
                           {5,3}};

int sarzamin_Africa[6][2]={{2,4},
                           {2,5},
                           {2,6},
                           {3,3},
                           {3,4},
                           {3,5}};

int person1[7][6]={0};
int person2[7][6]={0};
int person3[7][6]={0};
int person4[7][6]={0};

void person(void){
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_draw_filled_rectangle(400,400, 600,500,blue);
    al_draw_text(al_load_ttf_font("D:\\poroje\\risk\\tahoma.ttf",40,0),black,420,420,0,"2 person");
    al_draw_filled_rectangle(650,400, 850,500,green);
    al_draw_text(al_load_ttf_font("D:\\poroje\\risk\\tahoma.ttf",40,0),black,670,420,0,"3 person");
    al_draw_filled_rectangle(900,400, 1100,500,red);
    al_draw_text(al_load_ttf_font("D:\\poroje\\risk\\tahoma.ttf",40,0),black,920,420,0,"4 person");
    al_flip_display();
    al_rest(0.02);
}

void map(void) {
    al_clear_to_color(al_map_rgb(255,228,181));
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            if(j != 6 && i == 0){
                al_draw_filled_rectangle(150 * (i +1), 100 * (j +1), 150 * (i +1) + 150, 100 * (j +1) + 100,black);
            } else if (j < 2 && i == 1){
                al_draw_filled_rectangle(150 * (i +1), 100 * (j +1), 150 * (i +1) + 150, 100 * (j +1) + 100,black);
            } else if(j == 5 && i == 1){
                al_draw_filled_rectangle(150 * (i +1), 100 * (j +1), 150 * (i +1) + 150, 100 * (j +1) + 100,black);
            } else if(i <= 3 && i >= 2 && j<= 2){
                al_draw_filled_rectangle(150 * (i +1), 100 * (j +1), 150 * (i +1) + 150, 100 * (j +1) + 100,darkred);
            } else if(i >= 4 && j<= 3){
                al_draw_filled_rectangle(150 * (i +1), 100 * (j +1), 150 * (i +1) + 150, 100 * (j +1) + 100,green);
            } else if(i <= 3 && i >= 2 && j<= 5 && j >= 4){
                al_draw_filled_rectangle(150 * (i +1), 100 * (j +1), 150 * (i +1) + 150, 100 * (j +1) + 100,yellow);
            }else if(i == 3 && j == 3){
                al_draw_filled_rectangle(150 * (i +1), 100 * (j +1), 150 * (i +1) + 150, 100 * (j +1) + 100,yellow);
            }else if(j == 6 && i == 2){
                al_draw_filled_rectangle(150 * (i +1), 100 * (j +1), 150 * (i +1) + 150, 100 * (j +1) + 100,yellow);
            } else{
                al_draw_filled_rectangle(150 * (i +1), 100 * (j +1), 150 * (i +1) + 150, 100 * (j +1) + 100,skyblue);
            }
            al_draw_rectangle(150 * (i +1), 100 * (j +1), 150 * (i +1) + 150, 100 * (j +1) + 100, al_map_rgb(128,128,128),2);
        }
    }
}

void menu(void){
    font = al_load_ttf_font("D:\\poroje\\risk\\tahoma.ttf", 20, 0);
    al_draw_filled_rectangle(1300 , 25 , 1450 , 100 ,skyblue);
    al_draw_text(font,black,1350 , 45 , 0 , "menu");
}

void adad(float x1 , float y1 , int adad , int person){
    if(person == 1){
        font = al_load_ttf_font("D:\\poroje\\risk\\tahoma.ttf", 50, 0);
        if(adad < 10)
            al_draw_textf(font,chocolate,x1 + 60,y1 + 20 , 0 ,"%d",adad);
        else
            al_draw_textf(font,chocolate,x1 + 45,y1 + 20 , 0 ,"%d",adad);
        al_flip_display();
    } else if(person == 2){
        font = al_load_ttf_font("D:\\poroje\\risk\\tahoma.ttf", 50, 0);
        if(adad < 10)
            al_draw_textf(font,aqua,x1 + 60,y1 + 20 , 0 ,"%d",adad);
        else
            al_draw_textf(font,aqua,x1 + 45,y1 + 20 , 0 ,"%d",adad);
        al_flip_display();
    }
}

void randomsarbaz(int tedad , int *nafar1 , int *nafar2 , int *nafar3, int *nafar4) {
    int p1 = 0, p2 = 0, x, y;
    srand(time(0));
    if (tedad == 2) {
        for (int i = 28; i >= 0; i--) {
            int r = rand();
            if (i <= 8) {
                if (r % 2 == 0) {
                    if (p1 < 15) {
                        x = sarzaminha[i][0];
                        y = sarzaminha[i][1];
                        p1 += 1;
                        person1[y][x] = 1;
                        adad(150 * (x + 1), 100 * (y + 1), person1[y][x], 1);
                    } else{
                        while (p2 < 14){
                            p2 += 1;
                            x = sarzaminha[i][0];
                            y = sarzaminha[i][1];
                            person2[y][x] = 1;
                            adad(150 * (x + 1), 100 * (y + 1), person2[y][x], 2);
                            i -= 1;
                        }
                    }
                } else {
                    if (p2 < 15) {
                        x = sarzaminha[i][0];
                        y = sarzaminha[i][1];
                        p2 += 1;
                        person2[y][x] = 1;
                        adad(150 * (x + 1), 100 * (y + 1), person2[y][x], 2);
                    } else{
                        while (p1 < 14){
                            p1 += 1;
                            x = sarzaminha[i][0];
                            y = sarzaminha[i][1];
                            person1[y][x] = 1;
                            adad(150 * (x + 1), 100 * (y + 1), person1[y][x], 1);
                            i -= 1;
                        }
                    }
                }
            } else if(i <= 14){
                if (r % 2 == 0) {
                    if (p1 < 10) {
                        x = sarzaminha[i][0];
                        y = sarzaminha[i][1];
                        p1 += 1;
                        person1[y][x] = 1;
                        adad(150 * (x + 1), 100 * (y + 1), person1[y][x], 1);
                    } else {
                        while (p2 < 10) {
                            p2 += 1;
                            x = sarzaminha[i][0];
                            y = sarzaminha[i][1];
                            person2[y][x] = 1;
                            adad(150 * (x + 1), 100 * (y + 1), person2[y][x], 2);
                            i -= 1;
                        }
                        i += 1;
                    }
                } else {
                    if (p2 < 10) {
                        x = sarzaminha[i][0];
                        y = sarzaminha[i][1];
                        p2 += 1;
                        person2[y][x] = 1;
                        adad(150 * (x + 1), 100 * (y + 1), person2[y][x], 2);
                    }else {
                        while (p1 < 10) {
                            p1 += 1;
                            x = sarzaminha[i][0];
                            y = sarzaminha[i][1];
                            person1[y][x] = 1;
                            adad(150 * (x + 1), 100 * (y + 1), person1[y][x], 1);
                            i -= 1;
                        }
                        i += 1;
                    }
                }
                al_flip_display();
            } else if(i <= 22){
                if (r % 2 == 0) {
                    if (p1 < 7) {
                        x = sarzaminha[i][0];
                        y = sarzaminha[i][1];
                        p1 += 1;
                        person1[y][x] = 1;
                        adad(150 * (x + 1), 100 * (y + 1), person1[y][x], 1);
                    } else {
                        while (p2 < 7) {
                            p2 += 1;
                            x = sarzaminha[i][0];
                            y = sarzaminha[i][1];
                            person2[y][x] = 1;
                            adad(150 * (x + 1), 100 * (y + 1), person2[y][x], 2);
                            i -= 1;
                        }
                        i += 1;
                    }
                } else {
                    if (p2 < 7) {
                        x = sarzaminha[i][0];
                        y = sarzaminha[i][1];
                        p2 += 1;
                        person2[y][x] = 1;
                        adad(150 * (x + 1), 100 * (y + 1), person2[y][x], 2);
                    }else {
                        while (p1 < 7) {
                            p1 += 1;
                            x = sarzaminha[i][0];
                            y = sarzaminha[i][1];
                            person1[y][x] = 1;
                            adad(150 * (x + 1), 100 * (y + 1), person1[y][x], 1);
                            i -= 1;
                        }
                        i += 1;
                    }
                }
                al_flip_display();
            } else{
                if (r % 2 == 0) {
                    if (p1 < 3) {
                        x = sarzaminha[i][0];
                        y = sarzaminha[i][1];
                        p1 += 1;
                        person1[y][x] = 1;
                        adad(150 * (x + 1), 100 * (y + 1), person1[y][x], 1);
                    } else {
                        while (p2 < 3) {
                            p2 += 1;
                            x = sarzaminha[i][0];
                            y = sarzaminha[i][1];
                            person2[y][x] = 1;
                            adad(150 * (x + 1), 100 * (y + 1), person2[y][x], 2);
                            i -= 1;
                        }
                        i += 1;
                    }
                } else {
                    if (p2 < 3) {
                        x = sarzaminha[i][0];
                        y = sarzaminha[i][1];
                        p2 += 1;
                        person2[y][x] = 1;
                        adad(150 * (x + 1), 100 * (y + 1), person2[y][x], 2);
                    }else {
                        while (p1 < 3) {
                            p1 += 1;
                            x = sarzaminha[i][0];
                            y = sarzaminha[i][1];
                            person1[y][x] = 1;
                            adad(150 * (x + 1), 100 * (y + 1), person1[y][x], 1);
                            i -= 1;
                        }
                        i += 1;
                    }
                }
                al_flip_display();
            }
        }
        al_flip_display();
        *nafar1 = p1;
        *nafar2 = p2;
    }
}

void nobati(int nobat){
    font = al_load_ttf_font("D:\\poroje\\risk\\tahoma.ttf", 20, 0);
    al_draw_filled_rectangle(600 - 75,10,600 + 75,85 ,deeppink);
    if(nobat == 1)
        al_draw_rectangle(600 - 75,10,600 + 75,85,chocolate,10);
    else
        al_draw_rectangle(600 - 75,10,600 + 75,85,aqua,10);
    al_draw_textf(font,black,600 -40 , 30 , 0 , "person%d",nobat);
    al_flip_display();
}

void soldier(int tedad){
    if(tedad == 2) {
        font = al_load_ttf_font("D:\\poroje\\risk\\tahoma.ttf", 20, 0);
        al_draw_filled_circle(600 , 830 + 75/2,50, deeppink);
        al_draw_circle(600 , 830 + 75/2, 50,  chocolate, 10);
        al_draw_text(font, black, 600 - 35, 850, 0, "soldiers");
        al_flip_display();
    }
}

void get_sarbaz(int tedad , int p ,int nobat){
    if(tedad == 2){
        if(nobat == 1) {
            al_draw_filled_rectangle(450 - 75, 820, 450 + 75, 905, deeppink);
            al_draw_rectangle(450 - 75, 820, 450 + 75, 905, chocolate, 5);
            al_draw_rectangle(750 - 75, 820, 750 + 75, 905, white, 5);
            font = al_load_ttf_font("D:\\poroje\\risk\\tahoma.ttf", 50, 0);
            if(p > 9)
                al_draw_textf(font, chocolate, 425, 830, 0, "%d", p);
            else
                al_draw_textf(font, chocolate, 435, 830, 0, "%d", p);
        } else {
            al_draw_filled_rectangle(750 - 75, 820, 750 + 75, 905, deeppink);
            al_draw_rectangle(750 - 75, 820, 750 + 75, 905, aqua, 5);
            al_draw_rectangle(450 - 75, 820, 450 + 75, 905, white, 5);
            font = al_load_ttf_font("D:\\poroje\\risk\\tahoma.ttf", 50, 0);
            if(p > 9)
                al_draw_textf(font, aqua, 725, 830, 0, "%d", p);
            else
                al_draw_textf(font, aqua, 735, 830, 0, "%d", p);
        }
        al_flip_display();
    }
}

int select(int x1,int y1, int x2, int y2, int xmouse, int ymouse){
    if(xmouse>=x1 && xmouse<= x2 && ymouse>=y1 && ymouse<= y2 )
        return 1;
    return 0;
}

int select_map(int xmouse , int ymouse ,int person){
    if(person == 1) {
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 7; ++j) {
                if (person1[j][i] != 0 && select(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100, xmouse, ymouse)) {
                    if (j != 6 && i == 0 ) {
                        al_draw_filled_rectangle(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100,black);
                        al_draw_rectangle(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100,al_map_rgb(128, 128, 128), 2);
                        person1[j][i] += 1;
                        adad(150 * (i + 1), 100 * (j + 1), person1[j][i] , person);
                        return 1;
                    } else if (j < 2 && i == 1) {
                        al_draw_filled_rectangle(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100,black);
                        al_draw_rectangle(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100,al_map_rgb(128, 128, 128), 2);
                        person1[j][i] += 1;
                        adad(150 * (i + 1), 100 * (j + 1), person1[j][i],person);
                        return 1;
                    } else if (j == 5 && i == 1) {
                        al_draw_filled_rectangle(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100,black);
                        al_draw_rectangle(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100,al_map_rgb(128, 128, 128), 2);
                        person1[j][i] += 1;
                        adad(150 * (i + 1), 100 * (j + 1), person1[j][i] , person);
                        return 1;
                    } else if (i <= 3 && i >= 2 && j <= 2) {
                        al_draw_filled_rectangle(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100,darkred);
                        al_draw_rectangle(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100,al_map_rgb(128, 128, 128), 2);
                        person1[j][i] += 1;
                        adad(150 * (i + 1), 100 * (j + 1), person1[j][i] , person);
                        return 1;
                    } else if (i >= 4 && j <= 3) {
                        al_draw_filled_rectangle(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100,green);
                        al_draw_rectangle(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100,al_map_rgb(128, 128, 128), 2);
                        person1[j][i] += 1;
                        adad(150 * (i + 1), 100 * (j + 1), person1[j][i],person);
                        return 1;
                    } else if (i <= 3 && i >= 2 && j <= 5 && j >= 4) {
                        al_draw_filled_rectangle(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100,yellow);
                        al_draw_rectangle(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100,al_map_rgb(128, 128, 128), 2);
                        person1[j][i] += 1;
                        adad(150 * (i + 1), 100 * (j + 1), person1[j][i] ,person);
                        return 1;
                    } else if (i == 3 && j == 3) {
                        al_draw_filled_rectangle(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100,yellow);
                        al_draw_rectangle(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100,al_map_rgb(128, 128, 128), 2);
                        person1[j][i] += 1;
                        adad(150 * (i + 1), 100 * (j + 1), person1[j][i] ,person);
                        return 1;
                    } else if (j == 6 && i == 2) {
                        al_draw_filled_rectangle(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100,yellow);
                        al_draw_rectangle(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100,al_map_rgb(128, 128, 128), 2);
                        person1[j][i] += 1;
                        adad(150 * (i + 1), 100 * (j + 1), person1[j][i],person);
                        return 1;
                    }
                }
            }
        }
    }
    if(person == 2) {
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 7; ++j) {
                if (person2[j][i] != 0 &&select(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100, xmouse, ymouse)) {
                    if (j != 6 && i == 0) {
                        al_draw_filled_rectangle(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100,black);
                        al_draw_rectangle(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100,al_map_rgb(128, 128, 128), 2);
                        person2[j][i] += 1;
                        adad(150 * (i + 1), 100 * (j + 1), person2[j][i] , person);
                        return 1;
                    } else if (j < 2 && i == 1) {
                        al_draw_filled_rectangle(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100,black);
                        al_draw_rectangle(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100,al_map_rgb(128, 128, 128), 2);
                        person2[j][i] += 1;
                        adad(150 * (i + 1), 100 * (j + 1), person2[j][i] , person);
                        return 1;
                    } else if (j == 5 && i == 1) {
                        al_draw_filled_rectangle(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100,black);
                        al_draw_rectangle(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100,al_map_rgb(128, 128, 128), 2);
                        person2[j][i] += 1;
                        adad(150 * (i + 1), 100 * (j + 1), person2[j][i] , person);
                        return 1;
                    } else if (i <= 3 && i >= 2 && j <= 2) {
                        al_draw_filled_rectangle(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100,darkred);
                        al_draw_rectangle(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100,al_map_rgb(128, 128, 128), 2);
                        person2[j][i] += 1;
                        adad(150 * (i + 1), 100 * (j + 1), person2[j][i] , person);
                        return 1;
                    } else if (i >= 4 && j <= 3) {
                        al_draw_filled_rectangle(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100,green);
                        al_draw_rectangle(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100,al_map_rgb(128, 128, 128), 2);
                        person2[j][i] += 1;
                        adad(150 * (i + 1), 100 * (j + 1), person2[j][i] , person);
                        return 1;
                    } else if (i <= 3 && i >= 2 && j <= 5 && j >= 4) {
                        al_draw_filled_rectangle(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100,yellow);
                        al_draw_rectangle(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100,al_map_rgb(128, 128, 128), 2);
                        person2[j][i] += 1;
                        adad(150 * (i + 1), 100 * (j + 1), person2[j][i] , person);
                        return 1;
                    } else if (i == 3 && j == 3) {
                        al_draw_filled_rectangle(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100,yellow);
                        al_draw_rectangle(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100,al_map_rgb(128, 128, 128), 2);
                        person2[j][i] += 1;
                        adad(150 * (i + 1), 100 * (j + 1), person2[j][i] , person);
                        return 1;
                    } else if (j == 6 && i == 2) {
                        al_draw_filled_rectangle(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100,yellow);
                        al_draw_rectangle(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100,al_map_rgb(128, 128, 128), 2);
                        person2[j][i] += 1;
                        adad(150 * (i + 1), 100 * (j + 1), person2[j][i] , person);
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

void clear_get_sarbaz(void){
    al_draw_filled_rectangle(0, 800, 1500, 950, moccasin);
    al_draw_filled_rectangle(1100,150,1500,950,moccasin);
    al_flip_display();
}

void get_sarbaz2(int tedad , int select){
    if(tedad == 2) {
        font = al_load_ttf_font("D:\\poroje\\risk\\tahoma.ttf", 30, 0);
        al_draw_filled_rectangle(1275, 200, 1475, 300, blue);
        if(select == 0) {
            al_draw_text(font, yellow, 1300, 225, 0, "get soldiers");
        } else if(select == 1){
            al_draw_text(font,purple,1300,225,0,"get soldiers");
            al_draw_rectangle(1275 +5,200 +5 ,1475 -5,300 -5,purple,10);
        }
        al_flip_display();
    }
}

int hesab_sarbaz_ha(int person){
    int zamin = 0, zaminUSA = 0,zaminAsia = 0,zaminAfrica = 0,zaminEurope =0, gare = 0 , x ,y;
    if(person == 1) {
        for (int i = 0; i < 9; ++i) {
            x = sarzamin_USA[i][0];
            y = sarzamin_USA[i][1];
            if (person1[y][x] != 0){
                zaminUSA += 1;
//                printf("%d %d\n",x,y);
            }
        }
        if(zaminUSA == 9){
            gare += 3;
        }

        for (int i = 0; i < 6; ++i) {
            x = sarzamin_Europe[i][0];
            y = sarzamin_Europe[i][1];
            if (person1[y][x] != 0){
                zaminEurope += 1;
//                printf("%d %d\n",x,y);
            }
        }
        if(zaminEurope == 6){
            gare += 4;
        }

        for (int i = 0; i < 8; ++i) {
            x = sarzamin_Asia[i][0];
            y = sarzamin_Asia[i][1];
            if(person1[y][x] != 0){
                zaminAsia += 1;
//                printf("%d %d\n",x,y);
            }
        }
        if(zaminAsia == 8){
            gare += 4;
        }

        for (int i = 0; i < 6; ++i) {
            x = sarzamin_Africa[i][0];
            y = sarzamin_Africa[i][1];
            if(person1[y][x] != 0){
                zaminAfrica += 1;
//                printf("%d %d\n",x,y);
            }
        }
        if(zaminAfrica == 6){
            gare += 2;
        }

        zamin = zaminUSA +zaminEurope +zaminAsia +zaminAfrica +gare;
//        printf("%d %d\n",gare,zamin);
        return zamin;
    }
    if(person == 2) {
        for (int i = 0; i < 9; ++i) {
            x = sarzamin_USA[i][0];
            y = sarzamin_USA[i][1];
            if (person2[y][x] != 0){
                zaminUSA += 1;
//                printf("%d %d\n",x,y);
            }
        }
        if(zaminUSA == 9){
            gare += 3;
        }

        for (int i = 0; i < 6; ++i) {
            x = sarzamin_Europe[i][0];
            y = sarzamin_Europe[i][1];
            if (person2[y][x] != 0){
                zaminEurope += 1;
//                printf("%d %d\n",x,y);
            }
        }
        if(zaminEurope == 6){
            gare += 4;
        }

        for (int i = 0; i < 8; ++i) {
            x = sarzamin_Asia[i][0];
            y = sarzamin_Asia[i][1];
            if(person2[y][x] != 0){
                zaminAsia += 1;
//                printf("%d %d\n",x,y);
            }
        }
        if(zaminAsia == 8){
            gare += 4;
        }

        for (int i = 0; i < 6; ++i) {
            x = sarzamin_Africa[i][0];
            y = sarzamin_Africa[i][1];
            if(person2[y][x] != 0){
                zaminAfrica += 1;
//                printf("%d %d\n",x,y);
            }
        }
        if(zaminAfrica == 6){
            gare += 2;
        }

        zamin = zaminUSA +zaminEurope +zaminAsia +zaminAfrica +gare;
//        printf("%d %d",gare,zamin);
        return zamin;
    }
}

void print_tedad_sarbaz(int soldier , int person){
    font = al_load_ttf_font("D:\\poroje\\risk\\tahoma.ttf", 50, 0);
    al_draw_filled_circle(1175,250,50,white);
    if(person == 1) {
        if(soldier > 9)
            al_draw_textf(font, chocolate, 1145, 218, 0, "%d", soldier);
        else
            al_draw_textf(font, chocolate, 1160, 218, 0, "%d", soldier);
    }
    if(person == 2) {
        if(soldier > 9)
            al_draw_textf(font, aqua, 1145, 218, 0, "%d", soldier);
        else
            al_draw_textf(font, aqua, 1160, 218, 0, "%d", soldier);
    }
    al_flip_display();
}

void fight(int tedad ,int x1 , int y1 , int x2 , int y2, int z){
    if(tedad == 2) {
        font = al_load_ttf_font("D:\\poroje\\risk\\tahoma.ttf", 30, 0);
        al_draw_filled_rectangle(1275, 325, 1475, 425, blue);
        al_draw_filled_rectangle(1275, 450, 1475, 550, blue);
        if(z == 1) {
            al_draw_text(font, yellow, 1350, 350, 0, "fight");
            al_draw_text(font, yellow, 1280, 475, 0, "change soldier");
        } else {
            if (z == 2)
                al_draw_text(font, purple, 1350, 350, 0, "fight");
            else
                al_draw_text(font, yellow, 1350, 350, 0, "fight");
            if (z == 3)
                al_draw_text(font, purple, 1280, 475, 0, "change soldier");
            else
                al_draw_text(font, yellow, 1280, 475, 0, "change soldier");
            al_draw_rectangle(x1 +5,y1 +5 ,x2 -5,y2 -5,purple,10);
        }
        al_flip_display();
    }
}

void finish(void){
    al_draw_filled_rectangle(1275,600,1475,700,darkgreen);
    al_draw_text(font,yellow,1350,625,0,"finish");
    al_flip_display();
}

void finish2(int x){
    font = al_load_ttf_font("D:\\poroje\\risk\\tahoma.ttf", 30, 0);
    if(x == 1){
        al_draw_filled_rectangle(1150,325,1250,425,darkgreen);
        al_draw_text(font,yellow,1165,350,0,"finish");
    } else{
        al_draw_filled_rectangle(1150,450,1250,550,darkgreen);
        al_draw_text(font,yellow,1165,475,0,"finish");
    }
    al_flip_display();
}

void draw_circle(int x1 ,int y1){
    al_draw_circle(x1 + 75, y1+50,45,red,5);
    al_flip_display();
}

void dorost_select(int person ,int xmouse ,int ymouse){
    if(person == 1) {
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 7; ++j) {
                if (person1[j][i] != 0 && select(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100, xmouse, ymouse)) {
                    if (j != 6 && i == 0 ) {
                        draw_circle(150 * (i + 1), 100 * (j + 1));
                    } else if (j < 2 && i == 1) {
                        draw_circle(150 * (i + 1), 100 * (j + 1));
                    } else if (j == 5 && i == 1) {
                        draw_circle(150 * (i + 1), 100 * (j + 1));
                    } else if (i <= 3 && i >= 2 && j <= 2) {
                        draw_circle(150 * (i + 1), 100 * (j + 1));
                    } else if (i >= 4 && j <= 3) {
                        draw_circle(150 * (i + 1), 100 * (j + 1));
                    } else if (i <= 3 && i >= 2 && j <= 5 && j >= 4) {
                        draw_circle(150 * (i + 1), 100 * (j + 1));
                    } else if (i == 3 && j == 3) {
                        draw_circle(150 * (i + 1), 100 * (j + 1));
                    } else if (j == 6 && i == 2) {
                        draw_circle(150 * (i + 1), 100 * (j + 1));
                    }
                }
            }
        }
    }
}

int destroy_dorost_select(int person ,int xmouse ,int ymouse){
    if(person == 1) {
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 7; ++j) {
                if (person1[j][i] != 0 && select(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100, xmouse, ymouse)) {
                    if (j != 6 && i == 0 ) {
                        al_draw_filled_circle(150 * (i + 1) +140 , 100 * (j + 1) +50,5,black);
                        return 1;
                    } else if (j < 2 && i == 1) {
                        al_draw_filled_circle(150 * (i + 1) +140 , 100 * (j + 1) +50,5,black);
                        return 1;
                    } else if (j == 5 && i == 1) {
                        al_draw_filled_circle(150 * (i + 1) +140 , 100 * (j + 1) +50,5,black);
                        return 1;
                    } else if (i <= 3 && i >= 2 && j <= 2) {
                        al_draw_filled_circle(150 * (i + 1) +140 , 100 * (j + 1) +50,5,darkred);
                        return 1;
                    } else if (i >= 4 && j <= 3) {
                        al_draw_filled_circle(150 * (i + 1) +140 , 100 * (j + 1) +50,5,green);
                        return 1;
                    } else if (i <= 3 && i >= 2 && j <= 5 && j >= 4) {
                        al_draw_filled_circle(150 * (i + 1) +140 , 100 * (j + 1) +50,5,yellow);
                        return 1;
                    } else if (i == 3 && j == 3) {
                        al_draw_filled_circle(150 * (i + 1) +140 , 100 * (j + 1) +50,5,yellow);
                        return 1;
                    } else if (j == 6 && i == 2) {
                        al_draw_filled_circle(150 * (i + 1) +140 , 100 * (j + 1) +50,5,yellow);
                        return 1;
                    }
                }
            }
        }
        al_flip_display();
        return 0;
    }
}

void draw_dorost_circle(int i , int j){
    al_draw_circle(((i+1) * 150) + 75, ((j+1) * 100) + 50,45,white,5);
    al_flip_display();
}

void destroy_dorost_circle(void){
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 7; ++j) {
            if(j != 6 && i == 0){
                al_draw_circle(((i+1) * 150) + 75, ((j+1) * 100) + 50, 45,black,5);
            } else if (j < 2 && i == 1){
                al_draw_circle(((i+1) * 150) + 75, ((j+1) * 100) + 50, 45,black,5);
            } else if(j == 5 && i == 1){
                al_draw_circle(((i+1) * 150) + 75, ((j+1) * 100) + 50, 45,black,5);
            } else if(i <= 3 && i >= 2 && j<= 2){
                al_draw_circle(((i+1) * 150) + 75, ((j+1) * 100) + 50, 45,darkred,5);
            } else if(i >= 4 && j<= 3){
                al_draw_circle(((i+1) * 150) + 75, ((j+1) * 100) + 50, 45,green,5);
            } else if(i <= 3 && i >= 2 && j<= 5 && j >= 4){
                al_draw_circle(((i+1) * 150) + 75, ((j+1) * 100) + 50, 45,yellow,5);
            }else if(i == 3 && j == 3){
                al_draw_circle(((i+1) * 150) + 75, ((j+1) * 100) + 50, 45,yellow,5);
            }else if(j == 6 && i == 2){
                al_draw_circle(((i+1) * 150) + 75, ((j+1) * 100) + 50, 45,yellow,5);
            }
        }
    }
    al_flip_display();
}

void hamle_be_zamin_ha(int tedad ,int i , int j ,int person){
    if(tedad == 2){
        if(person == 1){
            if(i >= 1 && i <= 4 && j >= 1 && j <= 5){
                if(person2[j][i - 1] != 0){
                    draw_dorost_circle(i - 1 , j);
                }
                if(person2[j][i + 1] != 0){
                    draw_dorost_circle(i + 1 , j);
                }
                if(person2[j - 1][i] != 0){
                    draw_dorost_circle(i , j - 1);
                }
                if(person2[j + 1][i] != 0){
                    draw_dorost_circle(i , j + 1);
                }
            } else if (i == 0 && j != 0 && j != 6){
                if(person2[j][i + 1] != 0){
                    draw_dorost_circle(i + 1 , j);
                }
                if(person2[j - 1][i] != 0){
                    draw_dorost_circle(i , j - 1);
                }
                if(person2[j + 1][i] != 0){
                    draw_dorost_circle(i , j + 1);
                }
            } else if( j == 0 && i != 0 && i != 5){
                if(person2[j + 1][i] != 0){
                    draw_dorost_circle(i , j + 1);
                }
                if(person2[j][i + 1] != 0){
                    draw_dorost_circle(i + 1 , j);
                }
                if(person2[j][i - 1] != 0){
                    draw_dorost_circle(i - 1 , j);
                }
            } else if( i == 5 && j != 0 && j != 6){
                if(person2[j][i - 1] != 0){
                    draw_dorost_circle(i - 1 , j);
                }
                if(person2[j - 1][i] != 0){
                    draw_dorost_circle(i , j - 1);
                }
                if(person2[j + 1][i] != 0){
                    draw_dorost_circle(i , j + 1);
                }
            } else if ( j == 6 && i != 0 && i != 5){
                if(person2[j][i - 1] != 0){
                    draw_dorost_circle(i - 1 , j);
                }
                if(person2[j][i + 1] != 0){
                    draw_dorost_circle(i + 1 , j);
                }
                if(person2[j - 1][i] != 0){
                    draw_dorost_circle(i , j - 1);
                }
            } else if ( i == 0 && j == 0){
                if(person2[j][i + 1] != 0){
                    draw_dorost_circle(i + 1 , j);
                }
                if(person2[j + 1][i] != 0){
                    draw_dorost_circle(i , j + 1);
                }
            } else if( i == 5 && j == 0){
                if(person2[j + 1][i] != 0){
                    draw_dorost_circle(i , j + 1);
                }
                if(person2[j][i - 1] != 0){
                    draw_dorost_circle(i - 1 , j);
                }
            }
        }
    }
}

int dorost_select_map(int person ,int xmouse ,int ymouse , int fight){
    if(person == 1) {
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 7; ++j) {
                if (person1[j][i] != 0 && select(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100, xmouse, ymouse)) {
                    if (j != 6 && i == 0 ) {
                        if(fight == 1){
                            hamle_be_zamin_ha(2,i,j,person);
                        }
                        return 1;
                    } else if (j < 2 && i == 1) {
                        if(fight == 1){
                            hamle_be_zamin_ha(2,i,j,person);
                        }
                        return 1;
                    } else if (j == 5 && i == 1) {
                        if(fight == 1){
                            hamle_be_zamin_ha(2,i,j,person);
                        }
                        return 1;
                    } else if (i <= 3 && i >= 2 && j <= 2) {
                        if(fight == 1){
                            hamle_be_zamin_ha(2,i,j,person);
                        }
                        return 1;
                    } else if (i >= 4 && j <= 3) {
                        if(fight == 1){
                            hamle_be_zamin_ha(2,i,j,person);
                        }
                        return 1;
                    } else if (i <= 3 && i >= 2 && j <= 5 && j >= 4) {
                        if(fight == 1){
                            hamle_be_zamin_ha(2,i,j,person);
                        }
                        return 1;
                    } else if (i == 3 && j == 3) {
                        if(fight == 1){
                            hamle_be_zamin_ha(2,i,j,person);
                        }
                        return 1;
                    } else if (j == 6 && i == 2) {
                        if(fight == 1){
                            hamle_be_zamin_ha(2,i,j,person);
                        }
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
    if(person == 2) {
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 7; ++j) {
                if (person2[j][i] != 0 && select(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100, xmouse, ymouse)) {
                    if (j != 6 && i == 0 ) {
                        return 1;
                    } else if (j < 2 && i == 1) {
                        return 1;
                    } else if (j == 5 && i == 1) {
                        return 1;
                    } else if (i <= 3 && i >= 2 && j <= 2) {
                        return 1;
                    } else if (i >= 4 && j <= 3) {
                        return 1;
                    } else if (i <= 3 && i >= 2 && j <= 5 && j >= 4) {
                        return 1;
                    } else if (i == 3 && j == 3) {
                        return 1;
                    } else if (j == 6 && i == 2) {
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
}


void step(int step){
    if(step==1) {
        for (int i = 0; i < 100; ++i) {
            al_clear_to_color(white);
            font = al_load_ttf_font("D:\\poroje\\risk\\tahoma.ttf", i, 0);
            al_draw_textf(font, black, 600, 350, 0, "step %d", step);
            al_flip_display();
            al_rest(0.05);
        }
        for (int i = 100; i >= 0; ++i) {
            font = al_load_ttf_font("D:\\poroje\\risk\\tahoma.ttf", i, 0);
            al_draw_textf(font, black, 600, 350, 0, "step %d", step);
            al_flip_display();
            al_rest(0.05);
        }
    } else{
        for (int i = 0; i < 100; ++i) {
            font = al_load_ttf_font("D:\\poroje\\risk\\tahoma.ttf", i, 0);
            al_draw_textf(font, black, 600, 350, 0, "step %d", step);
            al_flip_display();
            al_rest(0.05);
        }
        for (int i = 100; i >= 0; ++i) {
            font = al_load_ttf_font("D:\\poroje\\risk\\tahoma.ttf", i, 0);
            al_draw_textf(font, black, 600, 350, 0, "step %d", step);
            al_flip_display();
            al_rest(0.05);
        }
    }
}
void select_person(int person){
    if(person == 2){
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_filled_rounded_rectangle(400,400, 600,500,50,50,blue);
        al_draw_text(al_load_ttf_font("D:\\poroje\\risk\\tahoma.ttf",40,0),black,420,420,0,"2 person");
        al_draw_filled_rectangle(650,400, 850,500,green);
        al_draw_text(al_load_ttf_font("D:\\poroje\\risk\\tahoma.ttf",40,0),black,670,420,0,"3 person");
        al_draw_filled_rectangle(900,400, 1100,500,red);
        al_draw_text(al_load_ttf_font("D:\\poroje\\risk\\tahoma.ttf",40,0),black,920,420,0,"4 person");
        al_flip_display();
        al_rest(0.02);
    } else if(person == 3){
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(400,400, 600,500,blue);
        al_draw_text(al_load_ttf_font("D:\\poroje\\risk\\tahoma.ttf",40,0),black,420,420,0,"2 person");
        al_draw_filled_rounded_rectangle(650,400, 850,500,50,50,green);
        al_draw_text(al_load_ttf_font("D:\\poroje\\risk\\tahoma.ttf",40,0),black,670,420,0,"3 person");
        al_draw_filled_rectangle(900,400, 1100,500,red);
        al_draw_text(al_load_ttf_font("D:\\poroje\\risk\\tahoma.ttf",40,0),black,920,420,0,"4 person");
        al_flip_display();
        al_rest(0.02);
    } else if(person == 4){
        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_filled_rectangle(400,400, 600,500,blue);
        al_draw_text(al_load_ttf_font("D:\\poroje\\risk\\tahoma.ttf",40,0),black,420,420,0,"2 person");
        al_draw_filled_rectangle(650,400, 850,500,green);
        al_draw_text(al_load_ttf_font("D:\\poroje\\risk\\tahoma.ttf",40,0),black,670,420,0,"3 person");
        al_draw_filled_rounded_rectangle(900,400, 1100,500,50,50,red);
        al_draw_text(al_load_ttf_font("D:\\poroje\\risk\\tahoma.ttf",40,0),black,920,420,0,"4 person");
        al_flip_display();
        al_rest(0.02);
    }
}
int darsadbazikonha(int tedad , int p1 , int p2 , int p3 , int p4){
    int x, y, darsad1 = 0, darsad2 = 0, darsad3 = 0, darsad4 = 0;
    if(tedad == 2){
        for (int i = 0; i < 8; ++i) {
            x = sarzamin_USA[i][0];
            y = sarzamin_USA[i][1];
            if(person1[y][x] != 0){
                darsad1 += 1;
            } else {
                darsad2 += 1;
            }
        }
    }
}
void get_soldier(int tedad, int p , int nobat){
    if(tedad == 2){
        if(nobat == 1) {
            al_draw_filled_rectangle(450 - 75, 820, 450 + 75, 905, deeppink);
            al_draw_rectangle(450 - 75, 820, 450 + 75, 905, chocolate, 5);
            al_draw_rectangle(750 - 75, 820, 750 + 75, 905, white, 5);
            font = al_load_ttf_font("D:\\poroje\\risk\\tahoma.ttf", 50, 0);
            if(p > 9)
                al_draw_textf(font, chocolate, 425, 830, 0, "%d", p);
            else
                al_draw_textf(font, chocolate, 435, 830, 0, "%d", p);
        } else {
            al_draw_filled_rectangle(750 - 75, 820, 750 + 75, 905, deeppink);
            al_draw_rectangle(750 - 75, 820, 750 + 75, 905, aqua, 5);
            al_draw_rectangle(450 - 75, 820, 450 + 75, 905, white, 5);
            font = al_load_ttf_font("D:\\poroje\\risk\\tahoma.ttf", 50, 0);
            if(p > 9)
                al_draw_textf(font, aqua, 725, 830, 0, "%d", p);
            else
                al_draw_textf(font, aqua, 735, 830, 0, "%d", p);
        }
        al_flip_display();
    }
}


int select_map2(int xmouse , int ymouse ,int person)    {
    if(person == 1) {
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 7; ++j) {
                if (person2[j][i] == 0 && select(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100, xmouse, ymouse)) {
                    if (j != 6 && i == 0 ) {
                        return 1;
                    } else if (j < 2 && i == 1) {
                        return 1;
                    } else if (j == 5 && i == 1) {
                        return 1;
                    } else if (i <= 3 && i >= 2 && j <= 2) {
                        return 1;
                    } else if (i >= 4 && j <= 3) {
                        return 1;
                    } else if (i <= 3 && i >= 2 && j <= 5 && j >= 4) {
                        return 1;
                    } else if (i == 3 && j == 3) {
                        return 1;
                    } else if (j == 6 && i == 2) {
                        return 1;
                    }
                }
            }
        }
    }else if(person == 2) {
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 7; ++j) {
                if (person1[j][i] == 0 &&select(150 * (i + 1), 100 * (j + 1), 150 * (i + 1) + 150, 100 * (j + 1) + 100, xmouse, ymouse)) {
                    if (j != 6 && i == 0) {
                        return 1;
                    } else if (j < 2 && i == 1) {
                        return 1;
                    } else if (j == 5 && i == 1) {
                        return 1;
                    } else if (i <= 3 && i >= 2 && j <= 2) {
                        return 1;
                    } else if (i >= 4 && j <= 3) {
                        return 1;
                    } else if (i <= 3 && i >= 2 && j <= 5 && j >= 4) {
                        return 1;
                    } else if (i == 3 && j == 3) {
                        return 1;
                    } else if (j == 6 && i == 2) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}


int main() {

    al_init();

    if (!al_init()) {
        printf("Could not init Allegro.\n");
        return -1;
    }

    al_install_keyboard();
    al_install_mouse();

    al_init_primitives_addon();
    al_init_font_addon();
    al_init_ttf_addon();

    ALLEGRO_TIMER *timer = al_create_timer(1.0 / 30.0);
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_DISPLAY *disp = al_create_display(1500, 950);
    ALLEGRO_MOUSE_STATE msestate;

    if (!disp) {
        printf("Error creating display\n");
        return -1;
    }

    font = al_load_ttf_font("D:\\poroje\\risk\\tahoma.ttf", 20, 0);

    if (!font) {
        printf("Error creating font\n");
        return -1;
    }

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    al_set_window_title(disp,"bazi risk");

    ALLEGRO_EVENT event;

    al_start_timer(timer);

    int tedad = 0, x = 0, y = 0 , nobat = 1 ,p1 , p2 , p3 , p4 , sarbaz ,break1 = 0 , z =0 , pos_xmouse , pos_ymouse , tedad_select =0;
    bool redraw = true;

    // moshakhas kardan tedad bazikon ha
    while(tedad == 0){
        if(al_is_event_queue_empty(queue)){
            person();
        }
        al_wait_for_event(queue, &event);
        al_rest(0.01);
        al_is_event_queue_empty(queue);
        al_wait_for_event(queue, &event);
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            break;

//        if(event.type == ALLEGRO_EVENT_MOUSE_AXES){
//            if(select(400,400, 600,500,event.mouse.x,event.mouse.y))
//                select_person(2);
//            if(select(650,400, 850,500,event.mouse.x,event.mouse.y))
//                select_person(3);
//            if(select(900,400, 1100,500,event.mouse.x,event.mouse.y))
//                select_person(4);
//            al_rest(0.01);
//        }
        if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
            if(select(400,400, 600,500,event.mouse.x,event.mouse.y))
                tedad=2;
            if(select(650,400, 850,500,event.mouse.x,event.mouse.y))
                tedad=3;
            if(select(900,400, 1100,500,event.mouse.x,event.mouse.y))
                tedad=4;
            al_rest(0.01);
        }
    }
    tedad = 2;
    map();
    menu();


    if(tedad == 2){
        randomsarbaz(tedad,&p1 , &p2 , &p3 ,&p4);
        if(p2 < p1)
            nobat = 2;
        p1 = 30 - p1;
        p2 = 30 - p2;
        nobati(nobat);

        soldier(tedad);
        get_sarbaz(tedad,p1,1);
        get_sarbaz(tedad,p2,2);
       while (p1 > 0 || p2 > 0) {
            al_is_event_queue_empty(queue);
            al_wait_for_event(queue, &event);
            if (event.type == ALLEGRO_EVENT_TIMER)
                redraw = true;
            else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
                break;
                if(al_show_native_message_box(NULL,"message","Are you sure that to exit??","  a",NULL,ALLEGRO_MESSAGEBOX_YES_NO)){
                    break;
                }
            }
            if(select(1300,25,1450,100,event.mouse.x,event.mouse.y) == 1){

            }
            if (redraw && al_is_event_queue_empty(queue)) {
                al_is_event_queue_empty(queue);
                al_wait_for_event(queue, &event);
                if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                    if(select_map(event.mouse.x ,event.mouse.y , nobat) == 1){
                        if(nobat == 1){
                            p1 -= 1;
                            get_sarbaz(tedad,p1,nobat);
                            nobat += 1;
                        } else{
                            p2 -= 1;
                            get_sarbaz(tedad,p2,nobat);
                            nobat = 1;
                        }
                        nobati(nobat);
                    }
                }
                al_flip_display();
                al_rest(0.01);
                redraw = false;
            }
        }

        al_flip_display();
        al_rest(2);

        clear_get_sarbaz();
        al_flip_display();

        while (1) {
            get_sarbaz2(tedad ,0);
            nobat = 1;
            nobati(nobat);
            while (1) {
                al_rest(0.01);
                al_is_event_queue_empty(queue);
                al_wait_for_event(queue, &event);
                if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
                    if (select(1275, 200, 1475, 300, event.mouse.x, event.mouse.y) == 1) {
                        get_sarbaz2(tedad ,1);
                        sarbaz = hesab_sarbaz_ha(nobat);
                        nobati(nobat);
                        print_tedad_sarbaz(sarbaz, nobat);
                        while (sarbaz != 0) {
                            al_rest(0.01);
                            al_is_event_queue_empty(queue);
                            al_wait_for_event(queue, &event);
                            if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
                                if (select_map(event.mouse.x, event.mouse.y, nobat) == 1) {
                                    sarbaz -= 1;
                                    print_tedad_sarbaz(sarbaz, nobat);
                                }
                            }
                        }
                        al_rest(1);
                        clear_get_sarbaz();
                        fight(tedad,0,0,0,0,1);
                        finish();
                        while (1) {
                            al_rest(0.01);
                            al_is_event_queue_empty(queue);
                            al_wait_for_event(queue, &event);
                            if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
                                if (select(1275, 325, 1475, 425, event.mouse.x, event.mouse.y) == 1) {
                                    fight(2, 1275, 325, 1475, 425, 2);
                                    finish2(1);
                                    while (1) {
                                        al_rest(0.01);
                                        al_is_event_queue_empty(queue);
                                        al_wait_for_event(queue, &event);
                                        if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
                                            if (tedad_select == 0 && dorost_select_map(nobat, event.mouse.x, event.mouse.y,1) == 1) {
                                                tedad_select = 1;
                                                dorost_select(nobat, event.mouse.x, event.mouse.y);
                                                while (1) {
                                                    al_rest(0.01);
                                                    al_is_event_queue_empty(queue);
                                                    al_wait_for_event(queue, &event);
                                                    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
                                                        if (select_map2(event.mouse.x, event.mouse.y,nobat)) {
                                                            printf("aaa%d\n",nobat);
                                                        }
                                                    }
                                                    if (select(1150, 325, 1250, 425, event.mouse.x, event.mouse.y) == 1) {
                                                        destroy_dorost_circle();
                                                        al_flip_display();
                                                        tedad_select = 0;
                                                        clear_get_sarbaz();
                                                        fight(tedad,0,0,0,0,1);
                                                        finish();
                                                        break;
                                                    }
                                                }
                                            }
                                            break;
                                        }
                                    }
                                    tedad_select = 0;
                                }
                                if (select(1275, 450, 1475, 550, event.mouse.x, event.mouse.y) == 1) {
                                    fight(2, 1275, 450, 1475, 550, 3);
                                    finish2(2);
                                    while (1){
                                        al_rest(0.01);
                                        al_is_event_queue_empty(queue);
                                        al_wait_for_event(queue, &event);
                                        if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP){
                                            if (dorost_select_map(nobat, event.mouse.x, event.mouse.y,2) == 1 && tedad_select == 0) {
                                                tedad_select = 1;
                                                dorost_select(nobat, event.mouse.x, event.mouse.y);
                                                pos_xmouse = event.mouse.x;
                                                pos_ymouse = event.mouse.y;
                                            }
                                            if(select(1150, 450, 1250, 550, event.mouse.x, event.mouse.y) == 1){
                                                destroy_dorost_select(nobat, pos_xmouse, pos_ymouse);
                                                al_flip_display();
                                                tedad_select = 0;
                                                clear_get_sarbaz();
                                                fight(tedad,0,0,0,0,1);
                                                finish();
                                                break;
                                            }
                                        }
                                    }
                                    tedad_select = 0;
                                }
                                if (select(1275, 600, 1475, 700, event.mouse.x, event.mouse.y) == 1) {
                                    clear_get_sarbaz();
                                    break1 = 1;
                                    break;
                                }
                            }
                        }

                    }
                    al_rest(0.01);
                    if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE || break1 == 1)
                        break;
                }
                if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                    break;
            }








            get_sarbaz2(tedad , 0);
            nobat = 2;
            nobati(nobat);
            printf("1\n");
            while (1) {
                al_rest(0.01);
                al_is_event_queue_empty(queue);
                al_wait_for_event(queue, &event);
                if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
                    if (select(1275, 200, 1475, 300, event.mouse.x, event.mouse.y) == 1) {
                        get_sarbaz2(tedad , 1);
                        sarbaz = hesab_sarbaz_ha(nobat);
                        print_tedad_sarbaz(sarbaz, nobat);
                        al_flip_display();
                        while (sarbaz != 0) {
                            al_rest(0.01);
                            al_is_event_queue_empty(queue);
                            al_wait_for_event(queue, &event);
                            if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
                                if (select_map(event.mouse.x, event.mouse.y, nobat) == 1) {
                                    sarbaz -= 1;
                                    print_tedad_sarbaz(sarbaz, nobat);
                                }
                            }
                        }
                        al_rest(1);
                        clear_get_sarbaz();
                        fight(tedad,0,0,0,0,1);
                        finish();
                        while (1) {
                            al_rest(0.01);
                            al_is_event_queue_empty(queue);
                            al_wait_for_event(queue, &event);
                            if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
                                if (select(1275, 325, 1475, 425, event.mouse.x, event.mouse.y) == 1) {
                                    fight(2, 1275, 325, 1475, 425, 2);
                                }
                                if (select(1275, 450, 1475, 550, event.mouse.x, event.mouse.y) == 1) {
                                    fight(2, 1275, 450, 1475, 550, 3);
                                }
                                if (select(1275, 600, 1475, 700, event.mouse.x, event.mouse.y) == 1) {
                                    break1 = 1;
                                    clear_get_sarbaz();
                                    break;
                                }
                            }
                        }
                    }

                    al_rest(0.01);
                    if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE || break1 == 1)
                        break;
                }
            }
        }
    }

    al_uninstall_mouse();
    al_uninstall_keyboard();

    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);


    return 0;
}
