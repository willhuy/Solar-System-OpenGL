#pragma once

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 2000
#define MAX_FACES 2000

float vertices[MAX_VERTICES][3];
int faces[MAX_FACES][3];

int shipAvailable;
int specialMode;
int vertexCount;
int facesCount;

void loadShip(const char* fileName);