#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<math.h>

int main() {
	int matrix[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
	printf("\n");
	printf("input matrix\n\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%3d  ", matrix[i][j]);
		}
		printf("\n\n");
	}
	int minor_matrix[4][4][3][3];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			for (int x = 0; x < 3; x++) {
				for (int y = 0; y < 3; y++) {
					if (x >= i) {
						if (y >= j) minor_matrix[i][j][x][y] = matrix[x + 1][y + 1];
						else minor_matrix[i][j][x][y] = matrix[x + 1][y];
					}
					else {
						if (y >= j) minor_matrix[i][j][x][y] = matrix[x][y + 1];
						else minor_matrix[i][j][x][y] = matrix[x][y];
					}
				}
			}
		}
	}
	printf("minor matrix\n\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("M_%d%d\t\t", i + 1, j + 1);
		}
		printf("\n\n");
		for (int x = 0; x < 3; x++) {
			for (int y = 0; y < 4; y++) {
				for (int z = 0; z < 3; z++) {
					printf("%3d  ", minor_matrix[i][y][x][z]);
				}
				printf("\t");
			}
			printf("\n\n");
		}
		printf("\n\n");
	}
	int minor_determinant[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			minor_determinant[i][j] 
				= (((minor_matrix[i][j][0][0] * minor_matrix[i][j][1][1] * minor_matrix[i][j][2][2])
				+   (minor_matrix[i][j][0][1] * minor_matrix[i][j][1][2] * minor_matrix[i][j][2][0])
				+   (minor_matrix[i][j][0][2] * minor_matrix[i][j][1][0] * minor_matrix[i][j][2][1]))
				-  ((minor_matrix[i][j][0][2] * minor_matrix[i][j][1][1] * minor_matrix[i][j][2][0])
				+   (minor_matrix[i][j][0][1] * minor_matrix[i][j][1][0] * minor_matrix[i][j][2][2])
				+   (minor_matrix[i][j][0][0] * minor_matrix[i][j][1][2] * minor_matrix[i][j][2][1])));
		}
	}
	printf("minor determinant\n\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%3d  ", minor_determinant[i][j]);
		}
		printf("\n\n");
	}
	int cofactor_matrix[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cofactor_matrix[i][j] = minor_determinant[i][j] * pow((-1), i + j + 2);
		}
	}
	printf("cofactor matrix\n\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%3d  ", cofactor_matrix[i][j]);
		}
		printf("\n\n");
	}
	int determinant = 0;
	for (int i = 0; i < 4; i++) {
		determinant = determinant + matrix[0][i] * cofactor_matrix[0][i];
	}
	printf("determinant = %d\n\n", determinant);
	int adjoint_matrix[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			adjoint_matrix[i][j] = cofactor_matrix[j][i];
		}
	}
	printf("adjoint matrix\n\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%3d  ", adjoint_matrix[i][j]);
		}
		printf("\n\n");
	}
	int printdeterminant = determinant;
	int printadjoint_matrix[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printadjoint_matrix[i][j] = adjoint_matrix[i][j];
		}
	}
	if (determinant < 0) {
		printdeterminant = -printdeterminant;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				printadjoint_matrix[i][j] = -printadjoint_matrix[i][j];
			}
		}
	}
	if (printdeterminant == 1) {
		printf("inverse matrix\n\n");
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				printf("%3d  ", printadjoint_matrix[i][j]);
			}
			printf("\n\n");
		}
	}
	else if (printdeterminant != 0) {
		printf("inverse matrix\n\n");
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				printf("%3d/%-3d  ", printadjoint_matrix[i][j], printdeterminant);
			}
			printf("\n\n");
		}
	}
	else printf("Inverse Matrix does not exist\n\n");
}