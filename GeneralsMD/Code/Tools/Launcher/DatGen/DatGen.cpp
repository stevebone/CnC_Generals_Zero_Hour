/*
**	Command & Conquer Generals Zero Hour(tm)
**	Copyright 2025 Electronic Arts Inc.
**
**	This program is free software: you can redistribute it and/or modify
**	it under the terms of the GNU General Public License as published by
**	the Free Software Foundation, either version 3 of the License, or
**	(at your option) any later version.
**
**	This program is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**	GNU General Public License for more details.
**
**	You should have received a copy of the GNU General Public License
**	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// DatGen.cpp : Defines the entry point for the application.
//

#include <cstdio>
#include <cstring>
#include <Debug\DebugPrint.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <memory.h>
#include <assert.h>
#include <windows.h>
#include <io.h>
#include "BFish.h"

void doIt(void)
{
	printf("Dat Generator Tool\n\n");

	// Get the passkey input safely
	char passKey[128];
	printf("Enter pass key: ");
	fgets(passKey, sizeof(passKey), stdin);
	passKey[strcspn(passKey, "\n")] = '\0';  // Remove trailing newline

	// Get the data input safely
	char dataStr[1024];
	printf("Enter the data to encode: ");
	fgets(dataStr, sizeof(dataStr), stdin);
	dataStr[strcspn(dataStr, "\n")] = '\0';  // Remove trailing newline

	printf("\nPasskey: %s\n", passKey);
	printf("Data: %s\n", dataStr);

	char outputFile[MAX_PATH];
	printf("Enter output file [Generals.dat]: ");

	if (fgets(outputFile, sizeof(outputFile), stdin) == NULL || outputFile[0] == '\n')
	{
		// Use default filename if input is empty
		strcpy(outputFile, "Generals.dat");
	}
	else
	{
		// Remove trailing newline
		outputFile[strcspn(outputFile, "\n")] = '\0';
	}

	printf("Output file: %s\n", outputFile);

	// Time to crunch the data
	printf("Encoding data...\n");

	// Get the length of the data
	int dataLen = strlen(dataStr);

	// Compute the length of the key
	int keyLen = strlen(passKey);
	if (keyLen > BlowfishEngine::MAX_KEY_LENGTH)
	{
		keyLen = BlowfishEngine::MAX_KEY_LENGTH;
	}

	// Compute required buffer size (rounded up to 8 byte boundary)
	int inBufferSize = ((dataLen / 8) + 1) * 8;

	printf("Data length: %d bytes\n", dataLen);
	printf("Rounded length: %d bytes\n", inBufferSize);

	// Create the input/output buffers
	char* inBuffer = new char[inBufferSize];
	char* outBuffer = new char[inBufferSize];

	// Initialize the buffers
	memset(inBuffer, 0, inBufferSize);
	memset(outBuffer, 0, inBufferSize);

	// Copy the data into the input buffer
	memcpy(inBuffer, dataStr, dataLen);

	// Setup the encryption
	BlowfishEngine blowfish;
	blowfish.Submit_Key(passKey, keyLen);
	blowfish.Encrypt(inBuffer, inBufferSize, outBuffer);

	// Write to file
	FILE* outFile = fopen(outputFile, "wb");
	if (outFile == NULL)
	{
		printf("ERROR creating output file!\n");
		exit(1);
	}

	fwrite(outBuffer, inBufferSize, 1, outFile);
	fclose(outFile);

	// Cleanup
	delete[] inBuffer;
	delete[] outBuffer;

	printf("Done! Created: %s\n", outputFile);
}

int main(int argc, char* argv[])
{
	doIt();

	return 0;
}


