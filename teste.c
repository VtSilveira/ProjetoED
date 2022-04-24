#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <ctype.h>

GtkWidget *window;
GtkWidget *fixed1;
GtkWidget *button1;
GtkWidget *nameEntry;
GtkWidget *ageEntry;
GtkWidget *urgencyImage;
GtkWidget *nameLabel;
GtkWidget *ageLabel;
GtkWidget *urgencyLabel;
GtkWidget *redButton;
GtkWidget *orangeButton;
GtkWidget *yellowButton;
GtkWidget *greenButton;
GtkWidget *blueButton;
GtkBuilder *builder;

int main(int argc, char *argv[]){

  gtk_init (&argc,&argv);

  builder = gtk_builder_new_from_file("edproject.glade");
  window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
  g_signal_connect (window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
  gtk_builder_connect_signals(builder, NULL);

  fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
  button1 = GTK_WIDGET(gtk_builder_get_object(builder, "button1"));
  nameEntry = GTK_WIDGET(gtk_builder_get_object(builder, "nameEntry"));
  ageEntry = GTK_WIDGET(gtk_builder_get_object(builder, "ageEntry"));
  urgencyImage = GTK_WIDGET(gtk_builder_get_object(builder, "urgencyImage"));
  urgencyLabel = GTK_WIDGET(gtk_builder_get_object(builder, "urgencyLabel"));
  ageLabel = GTK_WIDGET(gtk_builder_get_object(builder, "ageLabel"));
  nameLabel = GTK_WIDGET(gtk_builder_get_object(builder, "nameLabel"));
  redButton = GTK_WIDGET(gtk_builder_get_object(builder, "redButton"));
  orangeButton = GTK_WIDGET(gtk_builder_get_object(builder, "orangeButton"));
  yellowButton = GTK_WIDGET(gtk_builder_get_object(builder, "yellowButton"));
  greenButton = GTK_WIDGET(gtk_builder_get_object(builder, "greenButton"));
  blueButton = GTK_WIDGET(gtk_builder_get_object(builder, "blueButton"));

  gtk_widget_show(window);
  gtk_main();
  return EXIT_SUCCESS;
}