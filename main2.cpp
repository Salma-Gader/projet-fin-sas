#include <stdio.h>

//creation des strectures
struct donnesDeProduit{
    
  char code[15];
  char nom[30];
  int quantite;
  int prix[];
};

//declaration des variables globales
int choix,nmbProduit,nmbList;
struct donnesDeProduit produit[100];
static int stock=0;

//creation des fonctions
void ajouteProduit (){
    
    printf("entrer le code:\n");
    scanf("%s",&produit[stock].code);
    printf("entrer le nom:\n");
    scanf("%s",produit[stock].nom);
    printf("entrer le quantite:\n");
    scanf("%d",&produit[stock].quantite);
    printf("entrer le prix:\n");
    scanf("%d",&produit[stock].prix);
    stock++;
}    
void menuPrincipale(){

    printf("========= menu principal ====================\n\n");
    
	printf("=== 1-Ajouter un produit 		  ===\n");
	printf("=== 2-Ajouter plusieurs nouveaux produits ===\n");
	printf("=== 3-Lister tous les produits 		  ===\n");
	printf("=== 4-Acheter produit 			  ===\n");
	printf("=== 5-Rechercher des produits 		  ===\n");
	printf("=== 6-suprimer des produits 		  ===\n");
	printf("=== 7-Statistique de vente 		  ===\n\n");
	
	printf("=============================================\n");

}

tryAlphabetique(){
    int i,j;
    for(i=0;i<stock;i++)
    for(j=i+1;j<stock;j++);
    produit[i].prix>produit[j].prix
    
    
    
}
int main(){

	//fonction d'affichage de menu
	menuPrincipale();
	printf("entrer votre choix:\n");
	scanf("%d",&choix);
	switch(choix)
    {
        case 1:{
            ajouteProduit();
            break;
            
        }
         case 2:{
            printf("entrer le nombre de produits que vous voules Ajouter\n");
            scanf("%d",&nmbProduit);
            for (int i=0;i<nmbProduit;i++){
                ajouteProduit ();
                stock++;
            }
            break;
        }
         case 3:{
            
            printf("1-lister selon l'ordre alphabetique croissant\n ");
            printf("2-lister tous les produits selon l�ordre d�croissant du prix");
            printf("entrer votre choix");
            scanf("%d",&nmbList);
            switch(nmbList)
            case 1:{
                tryAlphabetique();
                
            }
            
            
             break;
        }
         case 4:{
            printf("case 4");
             break;
        }
         case 5:{
            printf("case 5");
             break;
        }
         case 6:{
            printf("case 6");
             break;
        }
         case 7:{
            
            printf("le total des prix des produits vendus en journ�e courante:\n");
            printf("la moyenne des prix des produits vendus en journ�e courante:\n");
            printf("le Max des prix des produits vendus en journ�e courante:\n");
            printf("le Min des prix des produits vendus en journ�e courante:\n");
             break;
        }
         default:
         break;
    }
	

	return 0;
}
