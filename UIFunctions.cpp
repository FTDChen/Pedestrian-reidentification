//
// Created by hya on 26.06.16.
//

#include "UIFunctions.h"

char *fileNameUI;
ReidentificationAlg *r;
bool started = false;

void on_startButton_clicked(GtkButton *button, gpointer user_data) {
    if (!started) {
        started = true;
        delete r;
        r = new ReidentificationAlg(fileNameUI);
        r->init();
        r->start();
    }
}

void on_fileChooserButton_file_set(GtkFileChooser *fileChooser) {
    fileNameUI = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(fileChooser));
}

void on_stopButton_clicked(GtkButton *button, gpointer user_data) {
    if (started) {
        r->stop();
        started = false;
    }
}

void on_window1_delete_event() {
    exit(-1);
}





