#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"
#include "time.h"

struct page_info {
	char buffer[32];
	bool used;
	int lastUsed;
	int pageId;
};

struct nonleafPage {
	char pageType;
	char unused[3];
	int children[4];
	int values[3];
};
struct leafPage {
	char pageType;
	char unused[4];
	int sid[3];
	char name[3][5];
};

void search(int id) {
	FILE* fp = fopen("file1.txt","r");
	struct nonleafPage np;
	fread(&np, sizeof(np), 1, fp);
	if(np.values[i])
}

void createTree() {
	FILE* fp = fopen("file.txt", "r");
	FILE* fp1 = fopen("file1.txt", "w");
	char line[10];
	int i = 0,j=0;
	struct leafPage pages[4];
	while (i<4) {
		fgets(line, sizeof line, fp);
		pages[i].pageType = 'l';
		int sid;
		char name[5];
		sscanf(line, "%d %s", &sid, name);
		pages[i].sid[j] = sid;
		strcpy(pages[i].name[j],name);
		j++;
		if (j == 3) {
			j = 0;
			i++;
		}
	}
	struct nonleafPage nonleaf;
	int offset = 0;
	nonleaf.pageType = '0';
	for (int i = 0;i < 4;i++) 
		nonleaf.children[i] = i;
	for (int i = 0;i < 3;i++)
		nonleaf.values[i] = pages[nonleaf.children[i + 1]].sid[0];
	fwrite(&nonleaf, sizeof(struct nonleafPage), 1, fp1);
	for (int i = 0;i < 4;i++) {
		fwrite(&pages[i], sizeof(struct leafPage), 1, fp1);
	}
	fclose(fp);
	fclose(fp1);
}

void write() {
	struct leafPage leaf1;
	struct leafPage leaf2;
	struct leafPage leaf3;
	struct leafPage leaf4;

	leaf1.pageType = 'l';
	leaf1.sid[0] = 10;
	leaf1.sid[1] = 20;
	leaf1.sid[2] = 30;
	strcpy(leaf1.name[0], "aman");
	strcpy(leaf1.name[1], "anu");
	strcpy(leaf1.name[2], "balu");

	leaf2.pageType = 'l';
	leaf2.sid[0] = 40;
	leaf2.sid[1] = 50;
	leaf2.sid[2] = 60;
	strcpy(leaf2.name[0], "bapu");
	strcpy(leaf2.name[1], "dan");
	strcpy(leaf2.name[2], "eega");

	leaf3.pageType = 'l';
	leaf3.sid[0] = 70;
	leaf3.sid[1] = 80;
	leaf3.sid[2] = 90;
	strcpy(leaf3.name[1], "guna");
	strcpy(leaf3.name[2], "hema");
	strcpy(leaf3.name[0], "fabc");

	leaf4.pageType = 'l';
	leaf4.sid[0] = 100;
	leaf4.sid[1] = 110;
	leaf4.sid[2] = 120;
	strcpy(leaf4.name[0], "isac");
	strcpy(leaf4.name[1], "jai");
	strcpy(leaf4.name[2], "kate");

	FILE* fp = fopen("file.txt", "w");
	fwrite(&leaf1, sizeof(struct leafPage), 1, fp);
	fwrite(&leaf2, sizeof(struct leafPage), 1, fp);
	fwrite(&leaf3, sizeof(struct leafPage), 1, fp);
	fwrite(&leaf4, sizeof(struct leafPage), 1, fp);
	fclose(fp);
}

void read() {
	FILE* fp = fopen("file.txt", "r");
	struct leafPage l1;
	struct leafPage l2;
	struct leafPage l3;
	struct leafPage l4;
	fread(&l1, sizeof(struct leafPage), 1, fp);
	fread(&l2, sizeof(struct leafPage), 1, fp);
	fread(&l3, sizeof(struct leafPage), 1, fp);
	fread(&l4, sizeof(struct leafPage), 1, fp);
	fclose(fp);
}

int main() {
	//write();
	//createTree();
	//read();
	search(50);
	return 0;
}