
#include <time.h> 
#include <stdio.h>
#include <string.h> 

//creation des strectures


struct donnesDeProduit{
    
  char code[15];
  char nom[30];
  int quantite;
  float prix;
  
};

//declaration des variables globales
int nmbProduit,nmbList,NbRecherche;
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
    scanf("%f",&produit[stock].prix);
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
	printf("=== 6-Etat du stock		  ===\n");
	printf("=== 7-Alimenter le stock		  ===\n");
	printf("=== 8-suprimer des produits 		  ===\n");
	printf("=== 9-Statistique de vente 		  ===\n\n");
	
	printf("=============================================\n");
	printf("entrer votre choix:\n");
	scanf("%d",&choix);
	return choix;

} 
//fonction d'affichage
void afficherProduit(){
	
	for(int i=0; i<stock; i++){
		float prixTTC = produit[i].prix + (produit[i].prix*0.15);
		printf("le code:%s\nle nom:%s\nla quantite:%d\nle prix:%.2f\nprixTTC:%.2f\n",produit[i].code,produit[i].nom,produit[i].quantite,produit[i].prix,prixTTC);
	}
}
//fonction de trie
void trieProduit(){
    

    printf("1-lister tous les produits selon lordre decroissant du prix\n");
    printf("2-lister selon lordre alphabetique croissant\n");
    printf("entrer votre choix:\n");
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
//fonction d'achat
void achaterProduit(struct donnesDeProduit produit[]){
	
    char code1[15];
    int Q,index;
    printf("entrer le code de produit");
    scanf("%s",code1);
        
        
	for(int i=0;i<stock;i++){
	   if(strcmp(produit[i].code,code1) == 0){
	    index=i;
	   	printf("%s   |\t%s    \t|\t Prix = %.2fDH   |  quantite  = %d  \n",produit[index].code,produit[index].nom,produit[index].prix,produit[index].quantite );
	   }
	   
	   printf("entrer la quantite de produit:\n");
       scanf("%d",&Q);
       
       for(int i=0;i<stock;i++){
        produit[index].quantite -= Q;
        printf("la quantite: %d\n",produit[index].quantite);
        float prixTTC = produit[index].prix + (produit[index].prix*0.15);
        time_t t;
    	time(&t);
    	printf("le PrixTTC : %.2f\nla date dachat : %s",prixTTC,ctime(&t));        
	   } 
	}
}    

//fonction de recherche par Code
void rechercheParCode(){
	
   char code1[20];
   printf("entrer le code de produit :\n");
   scanf("%s",code1);
   for(int i=0;i<stock;i++){
   	
	   if(strcmp(produit[i].code,code1) == 0){
	    printf("le produit existe" );
	   }else printf("le produit nexiste pas" );
    }
	   
}

// function de recherche par Quantite
void rechercheParQuantite(){
	
   int Quantite;
   printf("entrer le Quantite de produit :\n");
   scanf("%d",&Quantite);
   
   for(int i=0;i<stock;i++){
   	
	   if(produit[i].quantite == Quantite){
	    printf("le produit existe\n" );
	   }else printf("le produit nexiste pas\n" );
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
        achaterProduit(produit);
            
            break;
        
        case 5:
        	printf("1- Recherche par Code.\n2- Recherche par Quantite.\n");
        	printf("Entre le choix de Recherche :\n");
        	scanf("%d",&NbRecherche);
        	switch(NbRecherche){
        		case 1:
        			rechercheParCode();
        			break;
        		case 2:
        			rechercheParQuantite();
        			break;
			}
			break;
        
        case 6:
            printf("case 6");
            break;
        
        case 7:
            
            printf("le total des prix des produits vendus en journee courante:\n");
            printf("la moyenne des prix des produits vendus en journee courante:\n");
            printf("le Max des prix des produits vendus en journee courante:\n");
            printf("le Min des prix des produits vendus en journee courante:\n");
             break;
        
         default:
         break;
		 
    }
	}

	return 0;
}
