#include<gtk/gtk.h>
#include"chess.h"

enum piece chessBoard[8][8];
enum piece backRow[8] = {2,3,4,5,6,4,3,2};

GtkWidget *button[8][8];

void standard_board_setup(enum piece chessBoard[8][8]){
    //set up back row
    for(int i=0; i<8; i++){
        chessBoard[i][7] = -1*backRow[i];
    }
    //set pawns
    for(int i=0; i<8; i++){
        chessBoard[i][6] = bpawn;
    }
    for(int j=2; j<6;j++){
        for(int i=0; i<8; i++){
            chessBoard[i][j] = 0;
        }
    }
    //set pawns
    for(int i=0; i<8; i++){
        chessBoard[i][1] = wpawn;
    }
    //set up back row
    for(int i=0; i<8; i++){
        chessBoard[i][0] = backRow[i];
    }
}

void update_buttons(GtkWidget *button[][8]){
    char string[3];
    string[2] = '\0';
    for(int i=0; i<8; i++){
        for(int j=0; j<8;j++){
            if(chessBoard[i][j] >= 0){
                string[0] = ' ';
                string[1] = '0' + chessBoard[i][j];
            }else{
                string[0] = '-';
                string[1] = '0' + -1*chessBoard[i][j];
            }
            gtk_button_set_label(GTK_BUTTON(button[i][j]), string);
        }
    }
}



static void print_hello (GtkWidget *widget,
        gpointer data){
    g_print ("Hello World\n");
    update_buttons(button);
}

void gui_setup(){
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *tmpButton;
    char tmpString[2];
    char tmpString2[2];
    
    //window setup
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"Chess Board GUI");
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
 

    //setup grid
    grid = gtk_grid_new();
    gtk_container_add (GTK_CONTAINER (window), grid);
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);

    //lable edges
    tmpString[0] = '1';
    tmpString[1] = '\0';
    tmpString2[0] = 'a';
    tmpString2[1] = '\0';
    for(int i=0; i<8; i++){
        tmpButton = gtk_button_new_with_label(tmpString);
        gtk_grid_attach(GTK_GRID(grid), tmpButton, i+2, 10, 1, 2);
        tmpString[0]++;
        tmpButton = gtk_button_new_with_label(tmpString2);
        gtk_grid_attach(GTK_GRID(grid), tmpButton, 0, 9-i, 2, 1);
        tmpString2[0]++;
    }
    //fill grid
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            //buttons y inverted to line up with chess pieces 
            button[i][j] = gtk_button_new_with_label("0");
            g_signal_connect (button[i][j], "clicked", G_CALLBACK (print_hello), NULL);
            gtk_grid_attach(GTK_GRID(grid), button[i][j], i+2, 9-j, 1, 1);
        }
    }
    gtk_widget_show_all(window);
}
int main(int argc, char** argv){
    standard_board_setup(chessBoard); 
    
    
    gtk_init(&argc, &argv);
    gui_setup();
    gtk_main();
    
    return 0;
}
