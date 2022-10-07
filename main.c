#include <gtk/gtk.h>
#include <stdio.h>


GtkWidget *txtBin, *txtOcta, *txtHexa, *txtDec;

static void calcular(GtkWidget *widget, gpointer data) {
    int count = 0;
    const gchar *bin = gtk_entry_get_text(GTK_ENTRY(txtBin));
    const gchar *octal = gtk_entry_get_text(GTK_ENTRY(txtOcta));
    const gchar *deci = gtk_entry_get_text(GTK_ENTRY(txtDec));
    const gchar *hexa = gtk_entry_get_text(GTK_ENTRY(txtHexa));
    const gchar voi = "";

    //char binc[] = &bin;
    //printf("%s", binc);

    g_print("entry: %s\n", bin);
    g_print("entry: %s\n", octal);
    g_print("entry: %s\n", deci);
    g_print("entry: %s\n", hexa);

    // Validacion de datos enviados
    if (&bin != voi) {
        count++;
    }
    if (&octal != voi) {
        count++;
    }
    if (&deci != voi) {
        count++;
    }
    if (&hexa != voi) {
        count++;
    }

    if (count >= 1){
        g_print("Continue\n");
        count = 0;
    }
    

}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *fixed;
    GtkWidget *labelBin, *labelDec, *labelOcta, *labelHexa;
    GtkWidget *buttonBox, *button;

    // Create container
    fixed = gtk_fixed_new();

    // Create buton component
    buttonBox = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    button = gtk_button_new_with_label("Calcular");
     g_signal_connect (button, "clicked", G_CALLBACK (calcular), NULL);

    gtk_container_add(GTK_CONTAINER(buttonBox), button);
    gtk_fixed_put(GTK_FIXED(fixed), buttonBox, 140, 500);

    // Create entry text with label 
    txtBin = gtk_entry_new();
    labelBin = gtk_label_new("Binario");

    txtOcta = gtk_entry_new();
    labelOcta = gtk_label_new("Octal");
    txtHexa = gtk_entry_new();
    labelHexa = gtk_label_new("Hexadecimal");
    txtDec = gtk_entry_new();
    labelDec = gtk_label_new("decimal");

    gtk_fixed_put(GTK_FIXED(fixed), txtBin, 220, 100);
    gtk_fixed_put(GTK_FIXED(fixed), txtOcta, 220, 200);
    gtk_fixed_put(GTK_FIXED(fixed), txtDec, 220, 300);
    gtk_fixed_put(GTK_FIXED(fixed), txtHexa, 220, 400);

    gtk_fixed_put(GTK_FIXED(fixed), labelBin, 220, 85);
    gtk_fixed_put(GTK_FIXED(fixed), labelOcta, 220, 185);
    gtk_fixed_put(GTK_FIXED(fixed), labelDec, 220, 285);
    gtk_fixed_put(GTK_FIXED(fixed), labelHexa, 220, 385);

    // Create window aplication
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Window");
    gtk_window_set_default_size(GTK_WINDOW(window), 600, 600);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

    // add container at window
    gtk_container_add(GTK_CONTAINER(window), fixed);

    // Show all widgets
    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}