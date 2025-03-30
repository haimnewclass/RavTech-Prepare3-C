#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Document {
    int id;
    char title[50];
    char content[200];
    struct Document* next;
} Document;

typedef struct Category {
    char name[30];
    void* documents;  // מצביע גנרי עבור רשימת מסמכים
    struct Category* next;
} Category;

typedef struct Archive {
    Category* categories;
} Archive;

void* createDocument(int id, const char* title, const char* content) {
    Document* doc = (Document*)malloc(sizeof(Document));
    if (!doc) exit(1);
    doc->id = id;
    strcpy(doc->title, title);
    strcpy(doc->content, content);
    doc->next = NULL;
    return (void*)doc;
}

Category* createCategory(const char* name) {
    Category* category = (Category*)malloc(sizeof(Category));
    if (!category) exit(1);
    strcpy(category->name, name);
    category->documents = NULL;
    category->next = NULL;
    return category;
}

void addDocumentToCategory(Category* category, void* newDoc) {
    Document* docHead = (Document*)category->documents;
    if (!docHead) {
        category->documents = newDoc;
    }
    else {
        while (docHead->next) docHead = docHead->next;
        docHead->next = newDoc;
    }
}

void addCategory(Archive* archive, Category* newCategory) {
    Category* catHead = archive->categories;
    if (!catHead) {
        archive->categories = newCategory;
    }
    else {
        while (catHead->next) catHead = catHead->next;
        catHead->next = newCategory;
    }
}

void printArchive(Archive* archive) {
    Category* catPtr = archive->categories;
    while (catPtr) {
        printf("Category: %s\n", catPtr->name);
        Document* docPtr = (Document*)catPtr->documents;
        while (docPtr) {
            printf("  Document ID: %d, Title: %s\n", docPtr->id, docPtr->title);
            docPtr = docPtr->next;
        }
        catPtr = catPtr->next;
    }
}

void* findDocumentByID(Category* category, int id) {
    Document* docPtr = (Document*)category->documents;
    while (docPtr) {
        if (docPtr->id == id) return docPtr;
        docPtr = docPtr->next;
    }
    return NULL;
}

void* findCategory(Archive* archive, const char* name) {
    Category* catPtr = archive->categories;
    while (catPtr) {
        if (strcmp(catPtr->name, name) == 0) return catPtr;
        catPtr = catPtr->next;
    }
    return NULL;
}

void freeArchive(Archive* archive) {
    Category* catPtr = archive->categories;
    while (catPtr) {
        Document* docPtr = (Document*)catPtr->documents;
        while (docPtr) {
            Document* temp = docPtr;
            docPtr = docPtr->next;
            free(temp);
        }
        Category* temp = catPtr;
        catPtr = catPtr->next;
        free(temp);
    }
}

int main() {
    Archive archive = { NULL };

    Category* reports = createCategory("Reports");
    Category* letters = createCategory("Letters");

    addCategory(&archive, reports);
    addCategory(&archive, letters);

    addDocumentToCategory(reports, createDocument(1, "Annual Report", "This is the annual report content."));
    addDocumentToCategory(reports, createDocument(2, "Monthly Report", "This is the monthly report content."));
    addDocumentToCategory(letters, createDocument(3, "Invitation Letter", "This is an invitation letter."));

    printArchive(&archive);

    Document* foundDoc = (Document*)findDocumentByID(reports, 2);
    if (foundDoc) {
        printf("Found document: %s\n", foundDoc->title);
    }

    Category* foundCategory = (Category*)findCategory(&archive, "Letters");
    if (foundCategory) {
        printf("Found category: %s\n", foundCategory->name);
    }

    freeArchive(&archive);
    return 0;
}
