#include <stdio.h>
#include "driver.h"
#include "file.h"

void showHelp();

int main(int argc, char **argv) {
    Driver *drivers = NULL;
    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) showHelp();
        if (strcmp(argv[i], "-i") == 0) {
            for (int j = i + 1; j < argc; j++) {
                drivers = loadDataFromFile(argv[j], drivers);
            }
            saveDriverList(drivers);
        }
    }
    deleteDriverList(drivers);
    return 0;
}

void showHelp() {
    printf("Aby wczytac protokoly zawodow uzyj przelacznika -i\n"
           "PRZYKLAD UZYCIA:\n"
           "Race -i \"protokol1.txt\" \"protokol2\"\n"
           "Program wczyta wyniki z protokolow i zapisze je w plikach: NazwaKierowcy1.txt NazwaKierowcy2.txt\n");
}
//TODO refaktor
//TODO sprawko :/