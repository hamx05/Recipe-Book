#include "RecipeData.h"
#include <stdlib.h>

// Initialize ingredient options
struct Ingredient ingredientsOption[MAX_INGREDIENTS] = {
    {"Beef"}, {"Rice"}, {"Potato"}, {"Oil"}, {"Pulses"}, {"Onion"}, ("Tomato"),("Home Spices")
};

// Initialize recipes
struct Recipe recipes[MAX_RECIPES] = {
    {"Sindhi Biryani", {{"Beef"}, {"Rice"}, {"Potato"}, {"Oil"}}, 4},
    {"Nihari", {{"Beef"}, {"Oil"}}, 2},
    {"Haleem", {{"Beef"}, {"Pulses"}}, 2},
    {"Curry", {{"Pulses"}}, 1},
    {"Pulao", {{"Beef"}, {"Rice"}}, 2},
    // Recipes for Beef, Rice, and Pulses
    {"Beef Biryani", {{"Beef"}, {"Rice"}, {"Potato"}, {"Oil"}}, 4},
    {"Pakistani Beef Pulao", {{"Beef"}, {"Rice"}, {"Pulses"}, {"Onion"}}, 4},
    {"Spicy Lentil Curry", {{"Beef"}, {"Pulses"}, {"Home Spices"}}, 3},
    // Recipes for Beef, Rice, and Onion
    {"Karahi Beef", {{"Beef"}, {"Rice"}, {"Onion"}}, 3},
    {"Pakistani Beef Koftay", {{"Beef"}, {"Rice"}, {"Onion"}}, 3},
    {"Onion Pilaf", {{"Rice"}, {"Onion"}}, 2},
    // Recipes for Beef, Rice, and Tomatoes
    {"Pakistani Beef Bolognese", {{"Beef"}, {"Rice"}, {"Tomato"}}, 3},
    {"Tomato Beef Curry", {{"Beef"}, {"Rice"}, {"Tomato"}}, 3},
    {"Tomato Rice Delight", {{"Rice"}, {"Tomato"}}, 2},
    // Recipes for Beef, Pulses, and Onion
    {"Spicy Lentil and Beef Stew", {{"Beef"}, {"Pulses"}, {"Onion"}}, 3},
    {"Onion Beef Lentil Soup", {{"Beef"}, {"Pulses"}, {"Onion"}}, 3},
    // Recipes for Beef, Pulses, and Tomatoes
    {"Pakistani Beef Dal", {{"Beef"}, {"Pulses"}, {"Tomato"}}, 3},
    {"Tomato Beef Pulses Curry", {{"Beef"}, {"Pulses"}, {"Tomato"}}, 3},
    {"Spicy Tomato Beef Stew", {{"Beef"}, {"Pulses"}, {"Tomato"}}, 3},
    // Recipes for Beef, Onion, and Tomatoes
    {"Beef Karahi", {{"Beef"}, {"Onion"}, {"Tomato"}}, 3},
};

void printIngredients() {
    printf("===================\n");
    printf("* Ingredients *\n");
    printf("===================\n");
    printf("1. Beef\n");
    printf("2. Rice\n");
    printf("3. Potato\n");
    printf("4. Oil\n");
    printf("5. Pulses\n");
    printf("6. Onion\n");
	printf("7. Tomatoes\n");
	printf("8. Home Spices\n");
}

void selection(struct Ingredient *ingredientsOption, struct Ingredient *selectedIngredients, int *numSelectedIngredients) {
    int selected[MAX_INGREDIENTS];

    printIngredients();
    printf("Enter the number of ingredients you want to select: ");
    scanf("%d", numSelectedIngredients);
    if( *numSelectedIngredients>=9 || *numSelectedIngredients < 1 ||*numSelectedIngredients>='a'||*numSelectedIngredients>='A'){
    	printf("\nInvalid input. Please select from the above.\n");
    	exit (1);
	}
    
    
    for (int i = 0; i < *numSelectedIngredients; i++) {
        printf("Select Ingredient: ");
        scanf("%d", &selected[i]);
        if (selected[i] != 0) {
            strcpy(selectedIngredients[i].name, ingredientsOption[selected[i] - 1].name);
        } else {
		}
    }
}

void printSelectedIngredients(struct Ingredient *selectedIngredients, int numSelectedIngredients) {
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Selected Ingredients: ");

    for (int i = 0; i < numSelectedIngredients; i++) {
        printf("*%s ", selectedIngredients[i].name);
    }
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
} 

void search(struct Ingredient *selectedIngredients, struct Recipe *recipes, int numSelectedIngredients, int numRecipes, struct Ingredient *ingredientsOption) {
	int countPossible=0,countRecipe =0, view=0;
	
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Possible Recipes:\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    for (int i = 0; i < numRecipes; i++) {
        int matchCount = 0;
        for (int j = 0; j < recipes[i].numIngredients; j++) {
            for (int k = 0; k < numSelectedIngredients; k++) {
                if (strcmp(recipes[i].ingredients[j].name, selectedIngredients[k].name) == 0) {
                    // Ingredient found, increment matchCount
                    matchCount++;
                    break; // Move to the next ingredient in the recipe
                }
            }
        }

        // Check if all ingredients in the recipe are matched
        if (matchCount == recipes[i].numIngredients) {
        	countPossible++;
            // Print the matched recipe
            printf("\t%d. %s\n", i + 1, recipes[i].name);
        }
    }
    if (countPossible==0) {
    	printf("No recipe found with the selected ingredients.");
    	exit(1);
    	
	}
    
    printf("\nEnter 1 to view all the recipes or enter anything else to exit: ");
    scanf("%d", &view);
    if (view!=1) {
    	printf("The program has exit. Thank you for using our software.");
    	exit(1);
	} 
	
	//--------------------------------------------------------------------------------------------
	
	
    for (int i = 0; i < numRecipes; i++) {
        int matchCount = 0;
        for (int j = 0; j < recipes[i].numIngredients; j++) {
            for (int k = 0; k < numSelectedIngredients; k++) {
                if (strcmp(recipes[i].ingredients[j].name, selectedIngredients[k].name) == 0) {
                    // Ingredient found, increment matchCount
                    matchCount++;
                    break; // Move to the next ingredient in the recipe
                }
            }
        }
		
        // Check if all ingredients in the recipe are matched
        if (matchCount == recipes[i].numIngredients) {
        	countRecipe++;
            // Print the matched recipe
            //printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("\n\tRecipe %d: %s\n", countRecipe, recipes[i].name);
        	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        	
        	  if (strcmp(recipes[i].name, "Sindhi Biryani") == 0){
              	printf("Ingredients required: ");
            	for (int l = 0; l < recipes[i].numIngredients; l++) {
                printf("%s, ", recipes[i].ingredients[l].name); }
				printf("\n");
				printf("Cuisine Type: Pakistani\n");
                printf("Category: Main Course\n");
                printf("Cooking Time: 2.5 hours\n");
                printf("Calories: 500 cals\n");
                printf("Rating: 4.8\n");
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("\tSteps Of Cooking: \n");
                printf("1. Wash and soak 2 cups of basmati rice in water for 30 minutes.\n");
                printf("2. In a pot, heat 1/4 cup of cooking oil over medium heat.\n");
                printf("3. Add 1 kg of beef, cut into pieces, and saut� until browned on all sides.\n");
                printf("4. Add sliced onions and cook until golden brown.\n");
                printf("5. Stir in 2 tablespoons of ginger-garlic paste until aromatic.\n");
                printf("6. Add Sindhi Biryani masala, including cumin, coriander, and red chili powder.\n");
                printf("7. Peel and slice 2 potatoes, fry them until golden, and set aside.\n");
                printf("8. Parboil the soaked rice and layer it over the beef mixture.\n");
                printf("9. Arrange the fried potatoes on top and drizzle with saffron-infused milk.\n");
                printf("10. Cover and cook on low heat until the rice is tender. Serve hot with raita.\n");
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			}
              if (strcmp(recipes[i].name, "Nihari") == 0){
              	printf("Ingredients required: ");
            	for (int l = 0; l < recipes[i].numIngredients; l++) {
                printf("%s, ", recipes[i].ingredients[l].name); }
				printf("\n");
				printf("Cuisine Type: Pakistani\n");
                printf("Category: Main Course\n");
                printf("Cooking Time: 4 hours\n");
                printf("Calories: 480 cals\n");
                printf("Rating: 4.7\n");
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("\tSteps Of Cooking: \n");
                printf("1. In a pot, heat 1/2 cup of cooking oil over medium heat.\n");
                printf("2. Add 1 kg of beef, cut into pieces, and sear until browned on all sides.\n");
                printf("3. Add 3 tablespoons of ginger-garlic paste and saut� until fragrant.\n");
                printf("4. Pour in 8 cups of water, bring to a boil, and then simmer on low heat.\n");
                printf("5. Add Nihari masala, including coriander, cumin, fennel, and other spices.\n");
                printf("6. Allow the beef to cook on low heat for at least 3 hours until it's tender.\n");
                printf("7. In a separate pan, heat additional oil and saut� sliced onions until golden brown.\n");
                printf("8. Add the fried onions to the simmering beef, enhancing flavor and thickness.\n");
                printf("9. Adjust salt and continue simmering until the Nihari reaches a rich consistency.\n");
                printf("10. Garnish with fresh ginger slices and serve hot with naan or rice.\n");
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			  }
			  
            if (strcmp(recipes[i].name, "Curry") == 0) {
            	printf("Ingredients required: ");
            	for (int l = 0; l < recipes[i].numIngredients; l++) {
                printf("%s, ", recipes[i].ingredients[l].name); }
				printf("\n");
                printf("Cuisine Type: Various\n");
                printf("Category: Main Course\n");
                printf("Cooking Time: 1 hour\n");
                printf("Calories: 300 cals\n");
                printf("Rating: 4.0\n");
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("\tSteps Of Cooking: \n");
                printf("1. Wash and soak a mix of lentils and chickpeas in water for at least 2 hours.\n");
                printf("2. In a pot, heat 1/4 cup of cooking oil over medium heat.\n");
                printf("3. Saut� finely chopped onions until golden brown.\n");
                printf("4. Add 2 tablespoons of ginger-garlic paste and saut� until aromatic.\n");
                printf("5. Add a mix of soaked pulses to the pot and stir well.\n");
                printf("6. Pour in enough water to cover the pulses and bring to a boil.\n");
                printf("7. Add ground spices like cumin, coriander, and turmeric, adjusting to taste.\n");
                printf("8. Simmer on low heat until pulses are tender and the curry thickens.\n");
                printf("9. Season with salt according to taste.\n");
                printf("10. Garnish with fresh cilantro and serve hot with rice or bread.\n");
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");      
            }
            
            if (strcmp(recipes[i].name, "Pulao") == 0) {
            	printf("Ingredients required: ");
            	for (int l = 0; l < recipes[i].numIngredients; l++) {
                printf("%s, ", recipes[i].ingredients[l].name); }
				printf("\n");
                printf("Cuisine Type: Pakistani\n");
                printf("Category: Main Course\n");
                printf("Cooking Time: 1.5 hours\n");
                printf("Calories: 380 cals\n");
                printf("Rating: 4.2\n");
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("1. Wash and soak 2 cups of rice in water for 30 minutes.\n");
                printf("2. Cut 500g beef into cubes.\n");
                printf("4. Saut� sliced onions until golden brown.\n");
                printf("5. Add cubed beef and brown on all sides.\n");
                printf("6. Stir in 2 tablespoons of ginger-garlic paste until fragrant.\n");
                printf("7. Add whole spices like cinnamon, cardamom, and cloves.\n");
                printf("8. Drain soaked rice and add it to the pot. Stir gently.\n");
                printf("9. Pour in 4 cups of water, add salt to taste, and bring to a boil.\n");
                printf("10. Reduce heat, cover, and simmer until rice is tender. Serve hot.\n");   
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            }
            
            // Recipe: Beef Biryani
			if (strcmp(recipes[i].name, "Beef Biryani") == 0) {
            	printf("Ingredients required: ");
            	for (int l = 0; l < recipes[i].numIngredients; l++) {
                printf("%s, ", recipes[i].ingredients[l].name); }
				printf("\n");
   				printf("Cuisine Type: Pakistani\n");
    			printf("Category: Main Course\n");
    			printf("Cooking Time: 1.5 hours\n");
    			printf("Calories: 500 cals\n");
    			printf("Rating: 4.5\n");
    			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    			printf("\tSteps Of Cooking: \n");
    			printf("1. Marinate the beef with yogurt, spices, and a pinch of saffron.\n");
    			printf("2. Cook basmati rice separately with whole spices and parboil.\n");
    			printf("3. Layer the marinated beef and partially cooked rice in a pot.\n");
    			printf("4. Add fried onions, mint, and coriander leaves between the layers.\n");
    			printf("5. Cook on low heat until the beef is tender and the rice is fully cooked.\n");
    			printf("6. Garnish with additional fried onions and serve hot.\n");
    			printf("7. Enjoy your flavorful Beef Biryani!\n");
				printf("8. Serve with raita or salad on the side.\n");
    			printf("9. Pair with your favorite drink for a complete meal.\n");
    			printf("10. Share the deliciousness with family and friends.\n");
    			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			}
			
			// Recipe: Pakistani Beef Pulao
			if (strcmp(recipes[i].name, "Pakistani Beef Pulao") == 0) {
			printf("Ingredients required: ");
            	for (int l = 0; l < recipes[i].numIngredients; l++) {
                printf("%s, ", recipes[i].ingredients[l].name);
				}
				printf("\n");
    			printf("Cuisine Type: Pakistani\n");
				printf("Category: Main Course\n");
    			printf("Cooking Time: 1.5 hours\n");
    			printf("Calories: 450 cals\n");
    			printf("Rating: 4.3\n");
    			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    			printf("\tSteps Of Cooking: \n");
    			printf("1. Marinate the beef with yogurt and spices for at least 30 minutes.\n");
    			printf("2. Cook basmati rice until 70% done and set aside.\n");
    			printf("3. Saut� sliced onions until golden brown.\n");
    			printf("4. Add marinated beef and cook until browned.\n");
    			printf("5. Add tomatoes and cook until the oil separates.\n");
    			printf("6. Add water and bring it to a boil.\n");
    			printf("7. Add partially cooked rice and cook on low heat until done.\n");
    			printf("8. Garnish with fried onions and serve hot.\n");
    			printf("9. Enjoy the aromatic and flavorful Pakistani Beef Pulao!\n");
    			printf("10. Pair with yogurt or raita for a delightful meal.\n");
    			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			}

			// Recipe: Spicy Lentil Curry
			if (strcmp(recipes[i].name, "Spicy Lentil Curry") == 0) {
				printf("Ingredients required: ");
            	for (int l = 0; l < recipes[i].numIngredients; l++) {
                printf("%s, ", recipes[i].ingredients[l].name); }
				printf("\n");
    			printf("Cuisine Type: Pakistani\n");
    			printf("Category: Main Course\n");
    			printf("Cooking Time: 1 hour\n");
    			printf("Calories: 250 cals\n");
    			printf("Rating: 4.2\n");
    			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    			printf("\tSteps Of Cooking: \n");
    			printf("1. Wash lentils and cook until tender.\n");
    			printf("2. In a separate pan, saut� chopped onions, tomatoes, and spices until fragrant.\n");
    			printf("3. Add the cooked lentils to the saut�ed mixture and simmer until flavors combine.\n");
    			printf("4. Adjust salt and spices to taste.\n");
    			printf("5. Garnish with coriander leaves and serve hot with rice or bread.\n");
    			printf("6. Enjoy your Spicy Lentil Curry!\n");
    			printf("7. A squeeze of lemon can enhance the flavor.\n");
    			printf("8. Serve with naan or rice for a complete meal.\n");
    			printf("9. Share this hearty curry with your loved ones!\n");
    			printf("10. Experience the rich and spicy taste of Pakistani cuisine.\n");
    			printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			}

			// Recipe: Karahi Beef
			if (strcmp(recipes[i].name, "Karahi Beef") == 0) {
				printf("Ingredients required: ");
            	for (int l = 0; l < recipes[i].numIngredients; l++) {
                printf("%s, ", recipes[i].ingredients[l].name); }
				printf("\n");
			    printf("Cuisine Type: Pakistani\n");
			    printf("Category: Main Course\n");
			    printf("Cooking Time: 1 hour\n");
			    printf("Calories: 400 cals\n");
			    printf("Rating: 4.4\n");
			    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			    printf("\tSteps Of Cooking: \n");
			    printf("1. Marinate beef with yogurt, spices, and ginger-garlic paste for 1 hour.\n");
			    printf("2. Heat oil in a karahi and saut� sliced onions until golden brown.\n");
			    printf("3. Add marinated beef and cook until browned.\n");
			    printf("4. Add chopped tomatoes and cook until they soften.\n");
			    printf("5. Add green chilies, coriander powder, and garam masala.\n");
			    printf("6. Cook until the oil separates.\n");
			    printf("7. Garnish with fresh coriander and ginger slices.\n");
			    printf("8. Serve hot with naan or roti.\n");
			    printf("9. Enjoy the rich and spicy flavor of Karahi Beef!\n");
			    printf("10. Perfect for a festive dinner with family and friends.\n");
			    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			}

			// Recipe: Pakistani Beef Koftay
			if (strcmp(recipes[i].name, "Pakistani Beef Koftay") == 0) {
				printf("Ingredients required: ");
            	for (int l = 0; l < recipes[i].numIngredients; l++) {
                printf("%s, ", recipes[i].ingredients[l].name); }
				printf("\n");
			    printf("Cuisine Type: Pakistani\n");
			    printf("Category: Main Course\n");
			    printf("Cooking Time: 1.5 hours\n");
			    printf("Calories: 450 cals\n");
			    printf("Rating: 4.6\n");
			    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			    printf("\tSteps Of Cooking: \n");
			    printf("1. Prepare koftas by mixing minced beef, gram flour, and spices.\n");
			    printf("2. Shape the mixture into small balls and fry until golden brown.\n");
			    printf("3. Saut� onions, tomatoes, and spices in a separate pan.\n");
			    printf("4. Add water and bring to a simmer.\n");
			    printf("5. Gently add the fried koftas to the curry.\n");
			    printf("6. Cook on low heat until the koftas are cooked through.\n");
			    printf("7. Garnish with fresh coriander leaves.\n");
			    printf("8. Serve hot with rice or naan.\n");
			    printf("9. Experience the flavorful and aromatic Pakistani Beef Koftay!\n");
			    printf("10. A delicious twist to traditional kofta curry.\n");
			    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			}

			// Recipe: Onion Pilaf
			if (strcmp(recipes[i].name, "Onion Pilaf") == 0) {
				printf("Ingredients required: ");
            	for (int l = 0; l < recipes[i].numIngredients; l++) {
                printf("%s, ", recipes[i].ingredients[l].name); }
				printf("\n");
			    printf("Cuisine Type: Pakistani\n");
			    printf("Category: Main Course\n");
			    printf("Cooking Time: 1 hour\n");
			    printf("Calories: 300 cals\n");
			    printf("Rating: 4.1\n");
			    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			    printf("\tSteps Of Cooking: \n");
			    printf("1. Rinse and soak basmati rice for 30 minutes.\n");
			    printf("2. Saut� sliced onions in oil until golden brown.\n");
			    printf("3. Add soaked rice and saut� for a few minutes.\n");
			    printf("4. Add water, salt, and whole spices to the rice.\n");
			    printf("5. Cook on low heat until the rice is fully cooked.\n");
			    printf("6. Fluff the rice with a fork.\n");
			    printf("7. Garnish with fried onions and fresh coriander.\n");
			    printf("8. Serve hot as a side dish or main course.\n");
			    printf("9. Enjoy the fragrant and flavorful Onion Pilaf!\n");
			    printf("10. Perfect accompaniment to any curry or grilled meat.\n");
			    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			}
			// Recipe: Pakistani Beef Bolognese
			if (strcmp(recipes[i].name, "Pakistani Beef Bolognese") == 0) {
				printf("Ingredients required: ");
            	for (int l = 0; l < recipes[i].numIngredients; l++) {
                printf("%s, ", recipes[i].ingredients[l].name); }
				printf("\n");
			    printf("Cuisine Type: Pakistani\n");
			    printf("Category: Main Course\n");
			    printf("Cooking Time: 1.5 hours\n");
			    printf("Calories: 420 cals\n");
			    printf("Rating: 4.3\n");
			    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			    printf("\tSteps Of Cooking: \n");
			    printf("1. In a pan, saut� finely chopped onions and garlic until golden brown.\n");
			    printf("2. Add minced beef and cook until browned.\n");
			    printf("3. Add chopped tomatoes, tomato paste, and spices.\n");
			    printf("4. Simmer until the sauce thickens.\n");
			    printf("5. Cook pasta separately according to package instructions.\n");
			    printf("6. Mix the beef sauce with cooked pasta.\n");
			    printf("7. Garnish with fresh parsley and grated cheese.\n");
			    printf("8. Serve hot for a hearty Pakistani Beef Bolognese!\n");
			    printf("9. A delightful fusion of Pakistani and Italian flavors.\n");
			    printf("10. Share this unique dish with pasta lovers!\n");
			    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			}

			// Recipe: Tomato Beef Curry
			if (strcmp(recipes[i].name, "Tomato Beef Curry") == 0) {
				printf("Ingredients required: ");
            	for (int l = 0; l < recipes[i].numIngredients; l++) {
                printf("%s, ", recipes[i].ingredients[l].name); }
				printf("\n");
			    printf("Cuisine Type: Pakistani\n");
			    printf("Category: Main Course\n");
			    printf("Cooking Time: 1.5 hours\n");
			    printf("Calories: 380 cals\n");
			    printf("Rating: 4.2\n");
			    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			    printf("\tSteps Of Cooking: \n");
			    printf("1. Marinate beef with yogurt, ginger-garlic paste, and spices.\n");
			    printf("2. In a pan, saut� sliced onions until golden brown.\n");
			    printf("3. Add marinated beef and cook until browned.\n");
			    printf("4. Add chopped tomatoes and simmer until they turn into a thick gravy.\n");
			    printf("5. Adjust spices and salt to taste.\n");
			    printf("6. Garnish with fresh coriander leaves.\n");
			    printf("7. Serve hot with rice or naan.\n");
			    printf("8. Experience the rich and tangy flavor of Tomato Beef Curry!\n");
			    printf("9. Perfect for a comforting dinner.\n");
			    printf("10. Share with friends who love a good curry!\n");
			    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			}

			// Recipe: Tomato Rice Delight
			if (strcmp(recipes[i].name, "Tomato Rice Delight") == 0) {
				printf("Ingredients required: ");
            	for (int l = 0; l < recipes[i].numIngredients; l++) {
                printf("%s, ", recipes[i].ingredients[l].name); }
				printf("\n");
			    printf("Cuisine Type: Pakistani\n");
			    printf("Category: Main Course\n");
			    printf("Cooking Time: 1 hour\n");
			    printf("Calories: 350 cals\n");
			    printf("Rating: 4.0\n");
			    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			    printf("\tSteps Of Cooking: \n");
			    printf("1. Cook basmati rice separately until 70% done.\n");
			    printf("2. In a pan, saut� chopped tomatoes until they release their juices.\n");
			    printf("3. Add cooked rice to the pan and mix well.\n");
			    printf("4. Add spices and salt to taste.\n");
			    printf("5. Continue cooking until the rice is fully done.\n");
			    printf("6. Garnish with fresh coriander and mint leaves.\n");
			    printf("7. Serve hot as a delightful Tomato Rice Delight!\n");
			    printf("8. A simple yet flavorful rice dish.\n");
			    printf("9. Perfect for quick and tasty meals.\n");
			    printf("10. Enjoy with your favorite side dishes!\n");
			    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			}
			// Recipe: Haleem
			if (strcmp(recipes[i].name, "Haleem") == 0) {
				printf("Ingredients required: ");
            	for (int l = 0; l < recipes[i].numIngredients; l++) {
                printf("%s, ", recipes[i].ingredients[l].name); }
				printf("\n");
			    printf("Cuisine Type: Pakistani\n");
			    printf("Category: Main Course\n");
			    printf("Cooking Time: 3 hours\n");
			    printf("Calories: 600 cals\n");
			    printf("Rating: 4.7\n");
			    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			    printf("\tSteps Of Cooking: \n");
			    printf("1. Cook a mix of lentils, barley, and wheat until soft.\n");
			    printf("2. In a separate pot, cook shredded beef until tender.\n");
			    printf("3. Combine the cooked lentils, barley, wheat, and beef in a large pot.\n");
			    printf("4. Use a hand blender to blend the mixture into a thick, creamy consistency.\n");
			    printf("5. In a pan, saut� chopped onions, garlic, and ginger until golden.\n");
			    printf("6. Add home spices (cumin, coriander, turmeric, etc.) and stir.\n");
			    printf("7. Mix the saut�ed spices with the blended haleem mixture.\n");
			    printf("8. Simmer on low heat, stirring occasionally, until the haleem thickens.\n");
			    printf("9. Adjust salt and spices to taste.\n");
			    printf("10. Garnish with fried onions, mint leaves, and ginger slices.\n");
			    printf("11. Serve hot with naan or paratha.\n");
			    printf("12. Experience the rich and hearty flavor of Haleem!\n");
			    printf("13. Perfect for special occasions and festive gatherings.\n");
			    printf("14. Share this traditional dish with loved ones!\n");
			    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			}

			// Recipe: Spicy Lentil and Beef Stew
			if (strcmp(recipes[i].name, "Spicy Lentil and Beef Stew") == 0) {
				printf("Ingredients required: ");
            	for (int l = 0; l < recipes[i].numIngredients; l++) {
                printf("%s, ", recipes[i].ingredients[l].name); }
				printf("\n");
			    printf("Cuisine Type: Pakistani\n");
			    printf("Category: Main Course\n");
			    printf("Cooking Time: 2 hours\n");
			    printf("Calories: 500 cals\n");
			    printf("Rating: 4.5\n");
			    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			    printf("\tSteps Of Cooking: \n");
			    printf("1. Cook a mix of lentils, chickpeas, and beef in a large pot until tender.\n");
			    printf("2. In a separate pan, saut� chopped onions, garlic, and ginger until golden.\n");
			    printf("3. Add home spices (cumin, coriander, turmeric, etc.) to the saut�ed mixture.\n");
			    printf("4. Combine the saut�ed spices with the cooked lentils, chickpeas, and beef.\n");
			    printf("5. Simmer on low heat until the stew thickens.\n");
			    printf("6. Adjust salt and spices to taste.\n");
			    printf("7. Garnish with fresh coriander leaves.\n");
			    printf("8. Serve hot with rice or naan.\n");
			    printf("9. Enjoy the spicy and flavorful Lentil and Beef Stew!\n");
			    printf("10. A satisfying and nutritious dish for any occasion.\n");
			    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			}

			// Recipe: Onion Beef Lentil Soup
			if (strcmp(recipes[i].name, "Onion Beef Lentil Soup") == 0) {
				printf("Ingredients required: ");
            	for (int l = 0; l < recipes[i].numIngredients; l++) {
                printf("%s, ", recipes[i].ingredients[l].name); }
				printf("\n");
			    printf("Cuisine Type: Pakistani\n");
			    printf("Category: Soup\n");
			    printf("Cooking Time: 1.5 hours\n");
			    printf("Calories: 300 cals\n");
			    printf("Rating: 4.2\n");
			    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			    printf("\tSteps Of Cooking: \n");
			    printf("1. Cook lentils and beef in a pot until tender.\n");
			    printf("2. In a pan, saut� sliced onions until golden brown.\n");
			    printf("3. Add chopped tomatoes and cook until softened.\n");
			    printf("4. Combine the saut�ed mixture with the cooked lentils and beef.\n");
			    printf("5. Add water and bring to a simmer.\n");
			    printf("6. Season with spices and salt to taste.\n");
			    printf("7. Simmer on low heat until the soup reaches the desired consistency.\n");
			    printf("8. Garnish with fresh coriander leaves.\n");
			    printf("9. Serve hot as a comforting Onion Beef Lentil Soup!\n");
			    printf("10. Perfect for a cozy night in or a light meal.\n");
			    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			}

			// Recipe: Pakistani Beef Dal
			if (strcmp(recipes[i].name, "Pakistani Beef Dal") == 0) {
				printf("Ingredients required: ");
            	for (int l = 0; l < recipes[i].numIngredients; l++) {
                printf("%s, ", recipes[i].ingredients[l].name); }
				printf("\n");
			    printf("Cuisine Type: Pakistani\n");
			    printf("Category: Main Course\n");
			    printf("Cooking Time: 1.5 hours\n");
			    printf("Calories: 380 cals\n");
			    printf("Rating: 4.4\n");
			    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			    printf("\tSteps Of Cooking: \n");
			    printf("1. Cook lentils and beef in a pot until tender.\n");
			    printf("2. In a separate pan, saut� chopped onions until golden brown.\n");
			    printf("3. Add chopped tomatoes and cook until softened.\n");
			    printf("4. Combine the saut�ed mixture with the cooked lentils and beef.\n");
			    printf("5. Add spices and salt to taste.\n");
			    printf("6. Simmer on low heat until the dal reaches a thick consistency.\n");
			    printf("7. Garnish with fresh coriander leaves.\n");
			    printf("8. Serve hot with rice or naan.\n");
			    printf("9. Enjoy the delicious and protein-packed Pakistani Beef Dal!\n");
			    printf("10. A wholesome and flavorful dish for any meal.\n");
			    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			}

			// Recipe: Tomato Beef Pulses Curry
			if (strcmp(recipes[i].name, "Tomato Beef Pulses Curry") == 0) {
				printf("Ingredients required: ");
            	for (int l = 0; l < recipes[i].numIngredients; l++) {
                printf("%s, ", recipes[i].ingredients[l].name); }
				printf("\n");
			    printf("Cuisine Type: Pakistani\n");
			    printf("Category: Main Course\n");
			    printf("Cooking Time: 1.5 hours\n");
			    printf("Calories: 400 cals\n");
			    printf("Rating: 4.3\n");
			    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			    printf("\tSteps Of Cooking: \n");
			    printf("1. Cook a mix of lentils and chickpeas until tender.\n");
			    printf("2. In a pan, saut� sliced onions until golden brown.\n");
			    printf("3. Add marinated beef and cook until browned.\n");
			    printf("4. Add chopped tomatoes and simmer until they form a thick curry.\n");
			    printf("5. Add the cooked pulses to the curry mixture.\n");
			    printf("6. Season with spices and salt to taste.\n");
			    printf("7. Simmer on low heat until the curry reaches the desired consistency.\n");
			    printf("8. Garnish with fresh coriander leaves.\n");
			    printf("9. Serve hot with rice or naan.\n");
			    printf("10. Experience the hearty and wholesome Tomato Beef Pulses Curry!\n");
			    printf("11. A nutritious and flavorful addition to your meal.\n");
			    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			}

			// Recipe: Spicy Tomato Beef Stew
			if (strcmp(recipes[i].name, "Spicy Tomato Beef Stew") == 0) {
				printf("Ingredients required: ");
            	for (int l = 0; l < recipes[i].numIngredients; l++) {
                printf("%s, ", recipes[i].ingredients[l].name); }
				printf("\n");
			    printf("Cuisine Type: Pakistani\n");
			    printf("Category: Main Course\n");
			    printf("Cooking Time: 2 hours\n");
			    printf("Calories: 420 cals\n");
			    printf("Rating: 4.5\n");
			    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			    printf("\tSteps Of Cooking: \n");
			    printf("1. Cook a mix of lentils, chickpeas, and beef in a pot until tender.\n");
			    printf("2. In a separate pan, saut� chopped onions until golden brown.\n");
			    printf("3. Add chopped tomatoes and cook until softened.\n");
			    printf("4. Combine the saut�ed mixture with the cooked lentils, chickpeas, and beef.\n");
			    printf("5. Add spices and salt to taste.\n");
			    printf("6. Simmer on low heat until the stew reaches a thick and spicy consistency.\n");
			    printf("7. Garnish with fresh coriander leaves.\n");
			    printf("8. Serve hot with rice or naan.\n");
			    printf("9. Enjoy the bold and spicy flavor of Spicy Tomato Beef Stew!\n");
			    printf("10. A satisfying dish for spice lovers.\n");
			    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			}
			if (strcmp(recipes[i].name, "Beef Karahi") == 0){
				printf("Ingredients required: ");
            	for (int l = 0; l < recipes[i].numIngredients; l++) {
                printf("%s, ", recipes[i].ingredients[l].name); }
				printf("\n");
				printf("Cuisine Type: Pakistani\n");
                printf("Category: Main Course\n");
                printf("Cooking Time: 3 hours\n");
                printf("Calories: 380 cals\n");
                printf("Rating: 4.1\n");
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("\tSteps Of Cooking: \n");
                printf("1. Cut 500g beef into bite-sized pieces.\n");
                printf("2. Thinly slice 2 large onions.\n");
                printf("3. Chop 3 tomatoes.\n");
                printf("4. Heat 1/4 cup cooking oil in a karahi or deep pan over medium heat.\n");
                printf("5. Add 2 tablespoons of ginger-garlic paste and saut� until aromatic.\n");
                printf("6. Add cumin seeds to the hot oil and let them splutter.\n");
                printf("7. Saut� sliced onions until golden brown.\n");
                printf("8. Add marinated beef and cook until browned on all sides.\n");
                printf("9. Add chopped tomatoes, cook until soft, and spices. Mix well.\n");
                printf("10. Cover and simmer until the beef is tender. Garnish with coriander leaves and serve hot.\n");
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
			}
        }
    }
    if (countRecipe==0) {
        printf("No recipe found with the selected ingredients.");
	}
}