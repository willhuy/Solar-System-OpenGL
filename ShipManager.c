#include "ShipManager.h"

void loadShip(const char* fileName) {
    FILE* file = fopen(fileName, "r");
    
    if (!file) {
        printf("Could not open file\n");
        shipAvailable = 0;
        exit(1);
    }

    shipAvailable = 1;
    vertexCount = 0;
    facesCount = 0;

    char line[128];
    while (fgets(line, sizeof(line), file)) {
        if (line[0] == 'v') {
            // Parse vertex
            sscanf_s(line, "v %f %f %f", &vertices[vertexCount][0], &vertices[vertexCount][1], &vertices[vertexCount][2]);
            vertexCount++;
        }
        else if (line[0] == 'f') {
            // Parse face
            sscanf_s(line, "f %d %d %d", &faces[facesCount][0], &faces[facesCount][1], &faces[facesCount][2]);
            facesCount++;
        }
    }

    fclose(file);
}