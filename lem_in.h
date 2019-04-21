/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriiamuradian <valeriiamuradian@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:09:00 by vmuradia          #+#    #+#             */
/*   Updated: 2019/04/20 20:20:03 by valeriiamur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "./libft/libft.h"
# include "stdio.h"
# include "stdlib.h"

//struct for coordinates

typedef struct  s_coord
{
    int         x;
    int         y;
}               t_coord;

//main strct to save all ants related info

typedef struct s_farm
{
    int         ants;
    int         rooms;
    int         start;
    int         end;
    t_coord     coords_of_start;
    t_coord     coords_of_end; 
}               t_farm;

// A structure to represent an adjacency list node 
typedef struct AdjListNode 
{ 
    int dest; 
    struct AdjListNode* next; 
}; 
  
// A structure to represent an adjacency list 
typedef struct AdjList 
{ 
    struct AdjListNode *head;  
}; 
  
// A structure to represent a graph. A graph 
// is an array of adjacency lists. 
// Size of array will be V (number of vertices  
// in graph) 
typedef struct Graph 
{ 
    int V; 
    struct AdjList* array; 
}; 
  
// A utility function to create a new adjacency list node 
typedef struct AdjListNode* newAdjListNode(int dest) 
{ 
    struct AdjListNode* newNode = 
     (struct AdjListNode*) malloc(sizeof(struct AdjListNode)); 
    newNode->dest = dest; 
    newNode->next = NULL; 
    return newNode; 
} 

int     find_ants(t_farm farm);
int     find_end(t_farm farm, char *line);
void	ft_error(int code);

#endif
