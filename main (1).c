
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
   
	time_t tt = time(NULL);
	struct tm* dt = localtime(&tt);

typedef struct Date
	{
		int day;
		int mont;
		int year;
	}date;

typedef struct Produit 
	{
		int code ;
		char nom[40] ;
		int quantite ;
		float prix ;
		date dat;
	}produit;
	
	date dat2;
	
	int n=10;
	int jour = dt->tm_mday;
	float  prixTotal=0;
	int somQnt;
	
	bool CheckCode(produit T[],int *code,int *size )
	{
		for(int i = 0;i<*size;i++)
		{
			if(T[i].code==*code)
			{
			return true;
				break;
			}
		}
		 return false;
	}
	
	int Menu()
	{
		system("cls");
		int choix ,ch ;
		//affichage le menu
		
		printf("\n\n\n\n");
		printf("\t*********************************************************\a\n");
		printf("\t*	1  - Ajouter un nouveau produit \t\t*\n");
		printf("\t*	2  - Ajouter plusieurs nouveaux produits \t*\n");
		printf("\t*	3  - Lister tous les produits\t\t\t*\n");//***?????????
		printf("\t*	4  - Acheter produit\t\t\t\t*\n");
		printf("\t*	5  - Rechercher les produits Par\t\t*\n");
		printf("\t*	6  - Alimenter le stock\t\t\t\t*\n");
		printf("\t*	7  - Supprimer les produits\t\t\t*\n");
		printf("\t*	8  - Statistique de vente\t\t\t*\n");
		printf("\t*	0  - fermer \t\t\t\t\t*\n");
		printf("\t*********************************************************\n");	
		printf("\n\n\n\n");	
		//sleep(1);
		
		do
		{	
		printf("\nChoisissez le numéro de l'opération que vous souhaitez effectuer : ");
		scanf("%d",&choix);
		if(choix<0 && choix>9) 
		Menu();
		}while(choix<0 && choix>9);
		
		if(choix==0)
		return 0;
	
		return choix;
	}
	void AjouterUnProduit(produit T[],int *size)//1  - Ajouter un nouveau produit//son code, son nom, sa quantité, et son prix.
	{
		
		int i = *size;
		printf("i = %d",i);
		printf("Entrer le code : ");
		scanf("%d",&T[i].code);
		
		if(CheckCode(T,&T[i].code,&n))
		{
			printf("Le code deja exite ");
		}
		else
		{
			printf("Entrer le nom : ");
			scanf("%s",T[i].nom);
			
			printf("Entrer le quantite : ");
			scanf("%d",&T[i].quantite);
			
			printf("Entrer le prix : ");
			scanf("%f",&T[i].prix);
			
			printf("%d %s %d %2.f",T[i].code,T[i].nom,T[i].quantite,T[i].prix+(T[i].prix*0.15));
			
			(*size)++;
		}
	}
	
	AjouterPlusieursProduits(produit T[],int *size)//2  - Ajouter plusieurs nouveaux produits
	{
		do
		{
			printf("Entrez 0 dans le code lorsque vous avez termine\n");
			printf("Entrer le code : ");
			scanf("%d",&T[*size].code);
			if(T[*size].code==0) break ;
			
			if(CheckCode(T,&T[*size].code,&n))
			{
				printf("\nLe code deja exite ");
			}
			else
			{
				printf("\nEntrer le nom : ");
				scanf("%s",T[*size].nom);
				
				printf("Entrer le quantite : ");
				scanf("%d",&T[*size].quantite);
				
				printf("Entrer le prix : ");
				scanf("%f",&T[*size].prix);
				printf("****************************\n");
					(*size)++;
			}
		}while(T[*size].code!=0);
			
	}
	
	int ListerProduitNom(produit T[],int *size)// 3  - Lister pour le nom
	{
		system("cls");
		produit tmp;
		
		for(int i=0; i<*size; i++)
		    {
		        for(int j=0; j<*size; j++)
		        {
		            if(strcmp(T[i].nom, T[j].nom )< 0)
		            {
		                tmp=T[i];
		                T[i]=T[j];
		                T[j]=tmp;
		            }
		        }
		    }
		system("cls");
		for(int i=0 ;i<*size;i++)
		{
			printf("%d   \t%s    \t\t Prix = %.2fDH     \tprix TTC = %.2fDH  \n",T[i].code,T[i].nom,T[i].prix,T[i].prix+0.15 );
		}
	}
	///***********************************************
	void ListerProduitPrix(produit T[],int *size) //3  - Lister pour le prix 
	{
		
		produit tmp;
 	
		for(int i=0; i<*size; i++)
	    {
	        for(int j=0; j<*size; j++)
	        {
	            if(T[i].prix > T[j].prix )
	            {
	                tmp=T[i];
	                T[i]=T[j];
	                T[j]=tmp;
	            }
	        }
	    }
 		
		system("cls");
		for(int i=0 ;i<*size;i++)
		{
				
			printf("%d   \t%s    \t\t Prix = %.2fDH     \tprix TTC = %.2fDH  \n",T[i].code,T[i].nom,T[i].prix,T[i].prix+0.15 );
		}
	}
	
	void AcheterProduit(produit T[])//4  - Acheter produit
	{
		cass:
			int code,qnt;
			int index = -1;
			
			printf("Entrez le code que vous souhaitez acheter : ");
			scanf("%d",&code);
			
			for(int i=0;i<10;i++)
			{
				if(T[i].code==code)
				{
					index = i;
					break;
				}
			}
			
			if(index == -1)
			{
				printf("le code introuvable\n");
				goto cass;
			}
			
			
			printf("%d   |\t%s    \t|\t Prix = %.2fDH   |  \Qnt  = %d  \n",T[index].code,T[index].nom,T[index].prix+0.15,T[index].quantite );
			
			printf("Entrez la quantité que vous souhaitez acheter : ");
			scanf("%d",&qnt);
			
			for(int i=0;i<10;i++)
			{
				if(T[i].code==code)
				{
					T[i].quantite -= qnt;
					index = i;
					break;
				}
			}
			float prixTTC = T[index].prix+(T[index].prix*0.15);
			
			printf("%d   |\t%s    \t|\t Prix TTC = %.2fDH   |  \Qnt  = %d \t",T[index].code,T[index].nom,prixTTC*qnt,qnt );
			printf("la date acheter %.2d/%.2d/%.4d ",dt->tm_mday,dt->tm_mon+1,dt->tm_year+1900);
			T[index].dat.day  = dt->tm_mday;
			T[index].dat.mont = dt->tm_mon+1;
			T[index].dat.year = dt->tm_year+1900;
			
			prixTotal += prixTTC*qnt;
			somQnt += qnt;
		
	}

	void RechercherProduits(produit T[] ,int a)//5  - Rechercher les produits 
	{
		int code;
		int index = -1;
		if(a==51)//RACHERCHE AVEC UN CODE 
		{
			printf("Entrez le code rechercher : ");
			scanf("%d",&code);
			for(int i=0;i<=9;i++) 
			{
				if(T[i].code==code)
					{
						index = i;
						break;
					}
			}
			if(index==-1) printf("Le code introuvable");
			else
			printf("\nLe code = %d  \tLe nom = %s  \tPrix TTC = %.2fDH  \t Qnt  = %d \t",T[index].code,T[index].nom,T[index].prix+0.15,T[index].quantite );
		}
		else if (a==52) //RACHERCHE AVEC UNE QUANTITE
		{
			printf("Entrez la quantite rechercher : ");
			scanf("%d",&code);
			
			for(int i=0;i<=9;i++)
			{
				if(T[i].quantite==code)
					{
						index = i;
						printf("\nLe code = %d  \tLe nom = %s  \tPrix TTC = %.2fDH  \t Qnt  = %d \t",T[index].code,T[index].nom,T[index].prix+0.15,T[index].quantite );
						 
					}
			}
			if(index==-1) printf("Le code introuvable");
		}
		else if (a==53)//Etat du stock: permet d’afficher les produits dont la quantité est inférieure à 3
		{
			
			for(int i=0;i<=9;i++)
			{
				if(T[i].quantite<3)
					{
						index = i;
						printf("\nLe code = %d  \tLe nom = %s  \tPrix TTC = %.2fDH  \t Qnt  = %d \t",T[index].code,T[index].nom,T[index].prix+0.15,T[index].quantite );
					}
			}
		}
	}
	
	void AlimenterStock(produit T[])//	6  - Alimenter le stock
	{
		int code ,index =-1,qnt;
		c1:
		printf("Entrez le code modifie : ");
		scanf("%d",&code);
		for(int i=0;i<=9;i++) 
		{
			if(T[i].code==code)
				{
					index = i;
					break;
				}
		}
		if(index==-1)
		{
			printf("le code introuvable\n");
				goto c1;
		}
		else
		{
			printf("\nLe code = %d | Qnt  = %d \t\n",T[index].code,T[index].quantite );
			
			printf("\nEntrer le quantite : ");
			scanf("%d",&T[index].quantite);
			
		
			printf("\nLe code = %d | Qnt  = %d \t\n",T[index].code,T[index].quantite );
			
		}
	}

	void SupprimerProduits(produit T[],int *size)//7  - Supprimer les produits
	{
		c2:
		int code , index=-1;
		int n = *size;
		printf("\nEntrez le code de medicament Supprimer : ");
		scanf("%d",&code);
		for(int i=0;i<=n;i++) 
		{
			if(T[i].code==code)
				{
					index = i;
					break;
				}
		}
		if(index==-1) 
		{
			printf("le code introuvable\n");
				goto c2;
		}
		else
		{
			for(int i = index;i<n;i++)	
			{
				T[i] = T[i+1];
			}		
		}
		(*size)--;
	}

	void StatistiqueVente(produit T[],int *size)
		{
			float prixT = 0 , moyenne = 0 ;
			float max =-1, min = 100000;
			if(jour==dt->tm_mday)
				prixT = prixTotal ;
			moyenne = prixT/somQnt ;
			
			for(int i=0;i<*size;i++)
			if(T[i].prix > max)
			max = T[i].prix;
			
			for(int i=0;i<*size;i++)
			if(T[i].prix < min )
			min = T[i].prix;
			
			printf("Afficher le total des prix des produits vendus en journée courante est = %.2f\n",prixTotal);	
			printf("Afficher la moyenne des prix des produits vendus en journée courante est = %.2f\n",moyenne);
			printf("Afficher le Max des prix des produits vendus en journée courante = %.2f\n",max);
			printf("Afficher le Min des prix des produits vendus en journée courante est = %.2f\n",min);
				
				
			
		}

int main()
	{
			produit T[100];
			 
		{	 
		//DATA
			strcpy(T[0].nom,"Dopamine");
			strcpy(T[1].nom,"Felbamate");
			strcpy(T[2].nom,"Glyburide");
			strcpy(T[3].nom,"Amiloride");
			strcpy(T[4].nom,"Sertraline");
			strcpy(T[5].nom,"Imatinib");
			strcpy(T[6].nom,"Zanamivir");
			strcpy(T[7].nom,"DESFERAL");
			strcpy(T[8].nom,"Apixaban");
			strcpy(T[9].nom,"Indinavir");
			
			T[0].code = 1 ;
			T[1].code = 2 ;
			T[2].code = 3 ;
			T[3].code = 4 ;
			T[4].code = 5 ;
			T[5].code = 9 ;
			T[6].code = 7 ;
			T[7].code = 6 ;
			T[8].code = 8 ;
			T[9].code = 10 ;
			
			
			T[0].quantite = 133 ;
			T[1].quantite = 243 ;
			T[2].quantite = 32 ;
			T[3].quantite = 2 ;
			T[4].quantite = 1 ;
			T[5].quantite = 54 ;
			T[6].quantite = 7 ;
			T[7].quantite = 32 ;
			T[8].quantite = 52 ;
			T[9].quantite = 2 ;
			
			T[0].prix = 19 ;
			T[1].prix = 25 ;
			T[2].prix = 33 ;
			T[3].prix = 45 ;
			T[4].prix = 54 ;
			T[5].prix = 52 ;
			T[6].prix = 70 ;
			T[7].prix = 61 ;
			T[8].prix = 52 ;
			T[9].prix = 21 ;
		
}
		
		int totalPrix;
		int choix ;
		int ch ;
		
		
//		if(>-1){
//			printf("true");
//		}
//		else printf("false");
		
		
		ret:
		choix=-1 ;
		choix = Menu();
		
		system("cls");
		
		switch(choix)
		{
			case 1://1  - Ajouter un nouveau produit
					AjouterUnProduit(T,&n);	
						
				break;
			case 2://2  - Ajouter plusieurs nouveaux produits
					 AjouterPlusieursProduits(T,&n);
					
				break;
			case 3://3  - Lister tous les produits
						do
						{
							printf("Lister tous les produits par :\n");
							printf("1 - lister tous les produits selon l’ordre alphabetique  croissant du nom.\n");
							printf("2 - lister tous les produits selon l’ordre  decroissant du prix.\n");
							printf("0 - Accueil");
							printf("\nChoisissez le numero de l'operation que vous souhaitez effectuer : ");
							scanf("%d",&ch);
							switch(ch)
							{
								case 0:
									goto ret;
									break;
								case 1:
										ListerProduitNom(T,&n);	
									break;
								case 2:
									ListerProduitPrix(T,&n);
									break;
							}
							getch();
							system("cls");			
						}while(ch!=1 || ch!=2 || ch!=0);
				break;
			case 4://4  - Acheter produit
					 AcheterProduit(T);
				break;
			case 5://5  - Rechercher les produits Par
							
				do
				{
					printf("Rechercher les produits Par : \n");
					printf("1 - Code.\n");
					printf("2 - Quantité.\n");
					printf("3 - Etat du stock: permet d’afficher les produits dont la quantité est inférieure à 3.\n");
					printf("0 - Accueil\n");
					printf("\nChoisissez le numéro de l'opération que vous souhaitez effectuer : ");
					scanf("%d",&ch);
					
					switch(ch)
					{
						case 0:
							Menu();
							break;
						case 1:
							RechercherProduits(T,51); 
							break;
						case 2:
							RechercherProduits(T,52);
							break;
						case 3:
							RechercherProduits(T,53);
							break;
					}
							getch();
							system("cls");
				}while(ch!=1 || ch!=2 || ch!=3 || ch!=0);
				
					
				break;
			case 6://	6  - Alimenter le stock
					AlimenterStock(T);
				break;
			case 7://7  - Supprimer les produits
					SupprimerProduits(T,&n);
				break;
			case 8://8  - Statistique de vente
					StatistiqueVente(T,&n);
				break;

		}
		getch();
		system("cls");
		goto ret;
		
		getch();
		return 0;
	}
