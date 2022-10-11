#include <gtk/gtk.h>
#include <stdio.h>

GtkWidget *txtBin, *txtOcta, *txtHexa, *txtDec;
gchar letters[] = {'A', 'B', 'C', 'D', 'E', 'F'};

void binToDecimal(const gchar *reply, GString *value){

    GString afterPoint;
    GString beforePoint;

    // Separete string for point
    for (gint i = 0; i < value->len; i++) {
        if (value -> str[i] == '.'){
            afterPoint = g_string_new((value -> str[]));
        }
    }

    for (gint i = (value -> len) - 1; i >= 0; i--) {
        if (value -> str[i] == '1') {
            g_print("value: %c  pot: %ld \n", (value -> str[i]), (value->len - 1) - i);


        }
    }
}

// Crate new window and show messaege 
static void sendMessage (GtkWidget *widget, gchar *message, gchar *title) {
    GtkWidget *dialog, *label, *contentArea;
    GtkDialogFlags flags;

    // Create at window dialog with title, parent, flags, text in button
    dialog = gtk_dialog_new_with_buttons(title, NULL, flags, "Aceptar", GTK_RESPONSE_NONE, NULL);

    // Set properties at window dialog
    contentArea = gtk_dialog_get_content_area(GTK_DIALOG(dialog));
    gtk_window_set_default_size(GTK_WINDOW(dialog), 200, 200);
    gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER_ON_PARENT );
    gtk_window_set_resizable(GTK_WINDOW(dialog), FALSE);
    label = gtk_label_new(message);
    // gtk_label

    // Close window dialog to the price button accept
    g_signal_connect_swapped(dialog, "response", G_CALLBACK(gtk_widget_destroy), dialog);
    // Add witget and show result
    gtk_container_add(GTK_CONTAINER(contentArea), label);
    gtk_widget_show_all(dialog);
}

// Convert input a bases rest
static void convert (int id, GString *value) {
    gboolean flag = TRUE;
    gint64 band;
    const gchar *reply;
    // Selected convert correct
    switch (id) {
        // Cast from binary to rest bases
        case 0:
            // Iterat value (except char end string '\0')
            for (gint i = 0; i <= (value->len) - 1; i++) {
                // Compare chars the object string with '0', '1' y '.'
                if (!((value->str[i] == '0') || value->str[i] == '1' || value->str[i] == '.')) {
                    flag = FALSE;
                    break;
                }
            }

            if (flag) {
                g_print("continue\n");
                binToDecimal(reply, value);
                gtk_entry_set_text(GTK_ENTRY(txtDec), reply);
            } else {
                sendMessage(NULL, "Ingresar unicamente 0 y 1", "Aviso");
            }
            break;
        // Conversion for octal base
        case 1:
            g_print("before bucle octal\n");
            // Validacion para contener numeros
            for (gint i = 0; i <= (value->len) - 1; i++) {
                if (!g_ascii_isdigit(value->str[i])) {
                    flag = FALSE;
                    break;
                }
            }
            if (flag) {
                // Verificar nums < 8
                for (gint i = 0; i < value -> len; i++) {
                    if (!((value -> str[i]) < '8')) {
                        flag = FALSE;
                        break;
                    }
                }
                if (flag) {
                    g_print("Continue\n");
                    // Funcion para convertir de gstring a numero dep. la base. 0 para convertir tal cual
                    gint64 valInt = g_ascii_strtoll(value->str, NULL, 0);
                    g_print("%ld\n", valInt);

                    /* Convert base 8 at rest the bases */

                } else {
                    sendMessage(NULL, "La base octal opera en el rango de numeros 0 - 7", "Advertencia");
                }
            } else {
                sendMessage(NULL, "La base octal solo debe contener numeros", "Aviso");
            }
            break;
        // Verification for base hexadecimal 
        case 2:
            g_string_ascii_up(value);
            g_print("val: %s\n", value->str);
            flag = FALSE;
            gint coin = 0;
            for (gint i = 0; i < value -> len; i++) {
                // Validation for digit's
                if (g_ascii_isdigit(value->str[i])) {
                    // g_print("Digit\n");
                    if (!((value->str[i] <= 9) && (value->str[i] >= 0))) {
                        // g_print("digit on core\n");
                        coin++;
                    }
                // Validation for letters
                } else {
                    g_print("letter \n");
                    for (gint j = 0; j <= 5; j++) {
                        if (value->str[i] == letters[j]) {
                            flag = TRUE;
                            coin++;
                        } 
                    }
                }
            }
            // Decition final
            if (coin == (value -> len)) {
                g_print("continue\n");
                /* Convert actal to rest bases */
            } else {
                sendMessage(NULL, "Numero octal no valido", "Aviso");
            }
            break;
        case 3:
            band = g_ascii_strtoll(value -> str, NULL, 0);
            g_print("cod: %ld\n", band);
            if (band != 0) {
                g_print("continue\n");
                /* Convert decimal to rest bases */
            } else {
                sendMessage(NULL, "El decimal debe ser un numero diferente de 0", "Aviso");
            }
            break;
        default:
            break;
    }
}

// Funtion execute press button 'convertir'
static void calcular(GtkWidget *widget, gpointer data) {
    int count = 0;
    int id = 0;
    const gchar *value;
    // Get text the entry witgets
    const gchar *bin = gtk_entry_get_text(GTK_ENTRY(txtBin));
    const gchar *octal = gtk_entry_get_text(GTK_ENTRY(txtOcta));
    const gchar *deci = gtk_entry_get_text(GTK_ENTRY(txtDec));
    const gchar *hexa = gtk_entry_get_text(GTK_ENTRY(txtHexa));
    
    // Validacion de datos enviados a 1
     if ((strcmp(bin, "") != 0)) {
        count++;
        id = 0;
        value = bin;
    }
     if ((strcmp(octal, "") != 0)) {
        count++;
        id = 1;
        value = octal;
    }
     if ((strcmp(hexa, "") != 0)) {
        count++;
        id = 2;
        value = hexa;
    }
     if ((strcmp(deci, "") != 0)) {
        count++;
        id = 3;
        value = deci;
    }
    // num inputs need?
    if (count == 1) {
        GString *str = g_string_new(value);
        convert(id, str);
    } else {
        sendMessage(widget, "Solo debe ingresar un dato", "Advertencia");
    }
}
// Funtion construct
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
    // add button and set position in fixed 
    gtk_fixed_put(GTK_FIXED(fixed), buttonBox, 250, 500);

    // Create entry text with label 
    txtBin = gtk_entry_new();
    labelBin = gtk_label_new("Binario");

    txtOcta = gtk_entry_new();
    labelOcta = gtk_label_new("Octal");

    txtHexa = gtk_entry_new();
    labelHexa = gtk_label_new("Hexadecimal");

    txtDec = gtk_entry_new();
    labelDec = gtk_label_new("decimal");

    // Add witgets at fixed with position
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
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

    // add container at window
    gtk_container_add(GTK_CONTAINER(window), fixed);

    // Show all widgets
    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    // init window at app
    app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}

// Compiler: gcc `pkg-config --cflags gtk+-3.0` -o auto main.c `pkg-config --libs gtk+-3.0`
https://calcifer.org/documentos/librognome/glib-strings.html