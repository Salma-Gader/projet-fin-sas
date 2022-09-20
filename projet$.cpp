#include <stdio.h>
#include <string.h> 

//creation des strectures


struct donnesDeProduit{
    
  char code[15];
  char nom[30];
  int quantite;
  int prix;
};

//declaration des variables globales
int nmbProduit,nmbList;
struct donnesDeProduit produit[100];
static int stock=0;

//creation des fonctions
void ajouteProduit (){
    
    printf("entrer le code:\n");
    scanf("%s",produit[stock].code);
    printf("entrer le nom:\n");
    scanf("%s",produit[stock].nom);
    printf("entrer la quantite:\n");
    scanf("%d",&produit[stock].quantite);
    printf("entrer le prix:\n");
    scanf("%d",&produit[stock].prix);
    stock++;
}   
//declaration de fonction menu pricipale
int menuPrincipale(){
    int choix;
    printf("========= menu principal ====================\n\n");
    
	printf("=== 1-Ajouter un produit 		  ===\n");
	printf("=== 2-Ajouter plusieurs nouveaux produits ===\n");
	printf("=== 3-Lister tous les produits 		  ===\n");
	printf("=== 4-Acheter produit 			  ===\n");
	printf("=== 5-Rechercher des produits 		  ===\n");
	printf("=== 6-suprimer des produits 		  ===\n");
	printf("=== 7-Statistique de vente 		  ===\n\n");
	
	printf("=============================================\n");
	printf("entrer votre choix:\n");
	scanf("%d",&choix);
	return choix;

}
void afficherProduit(){
	for(int i=0; i<stock; i++){
		printf("%s %s %d %d\n",produit[i].code,produit[i].nom,produit[i].quantite,produit[i].prix);
	}
}
void trieProduit(){
    

    printf("1-lister tous les produits selon l’ordre décroissant du prix\n");
    printf("2-lister selon l'ordre alphabetique croissant\n");
    printf("entrer votre choix");
    int i,j;
    struct donnesDeProduit tmp;
    struct donnesDeProduit temp;
    scanf("%d",&nmbList);
        switch(nmbList) {
            case 1:
            
            for(i=0;i<stock;i++){
            for(j=i+1;j<stock;j++){
            	 if(produit[i].prix<produit[j].prix){
            tmp=produit[i] ;
            produit[i]= produit[j];
            produit[j] = tmp;}
                
			}
		}
		afficherProduit();
			break;
            case 2:
            for(i=0;i<stock;i++)
			{
	            for(j=0;j<stock;j++)
				{
		            if(strcmp(produit[i].nom,produit[j].nom)<0)
					{
			            temp =produit[i];
			            produit[i]= produit[j];
			            produit[j]= temp;
					}
	          	}
           }
           afficherProduit();
            break;
            default:
            break;
            
            
    }
}
int main(){
    int n;
	//fonction d'affichage de menu
	
	while(1) {
	    
	n = menuPrincipale();   
	switch(n)
    {
        case 1:
            ajouteProduit();
            break;
            
        
        case 2:
            printf("entrer le nombre de produits que vous voules Ajouter\n");
            scanf("%d",&nmbProduit);
            for (int i=0;i<nmbProduit;i++){
            ajouteProduit ();
										  }
            break;
        
        case 3 :
            
            trieProduit();
                
            break;
        
        case 4:
            printf("case 4");
            break;
        
        case 5:
            printf("case 5");
            break;
        
        case 6:
            printf("case 6");
            break;
        
        case 7:
            
            printf("le total des prix des produits vendus en journée courante:\n");
            printf("la moyenne des prix des produits vendus en journée courante:\n");
            printf("le Max des prix des produits vendus en journée courante:\n");
            printf("le Min des prix des produits vendus en journée courante:\n");
             break;
        
         default:
         break;
		 
    }
	}
    
	return 0;
}
