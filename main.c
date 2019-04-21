/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriiamuradian <valeriiamuradian@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 20:23:29 by valeriiamur       #+#    #+#             */
/*   Updated: 2019/04/20 20:28:35 by valeriiamur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int main() 
{ 
    t_farm *farm;

    farm = malloc(sizeof(struct t_farm));
	if (find_ants(farm))
        read_links(farm);
    // print the adjacency list representation of the above graph 
    printGraph(graph); 
}

int find_ants(t_farm farm)
{
	char *line;
	char **data;

	get_next_line(0, &line);
	farm.ants = ft_atoi(line);
	if (farm.ants <= 0)
		ft_error(1);
	printf ("The number of ants is %d\n", farm.ants);
	while (ft_strncmp(line, "##start", 7) != 0)
	{
		free(line);
		get_next_line(0, &line);
	}
	get_next_line(0, &line);
	data = ft_strsplit(line, ' ');
	farm.start = ft_atoi(data[0]);
	farm.coords_of_start.x = ft_atoi(data[1]);
	farm.coords_of_start.y = ft_atoi(data[2]);
	printf("The ants are in the room number %d, the coords are x %d and y %d\n", farm.start, farm.coords_of_start.x, farm.coords_of_start.y);
	free_2d((void*)data, 3);
	free(line);
	// find_end(farm, line);
    read_links(farm, line);
	return (1);
}

void read_links(f_farm *farm, char *line)
{
    printf("The line is now here %s", &line);
    // create the graph  
    int V = 5; 
    struct Graph* graph = createGraph(V); 
    char **data;
    while (get_next_line(fd, &line))
    {
        data = ft_strsplit(line, ' ')
        addEdge(graph, data[1], data[2])
    }
    // addEdge(graph, 0, 1); 
    // addEdge(graph, 0, 4); 
    // addEdge(graph, 1, 2); 
    // addEdge(graph, 1, 3); 
    // addEdge(graph, 1, 4); 
    // addEdge(graph, 2, 3); 
    // addEdge(graph, 3, 4); 
  
}

// A utility function that creates a graph of V vertices 
struct Graph* createGraph(int V) 
{ 
    struct Graph* graph =  
        (struct Graph*) malloc(sizeof(struct Graph)); 
    graph->V = V; 
  
    // Create an array of adjacency lists.  Size of  
    // array will be V 
    graph->array =  
      (struct AdjList*) malloc(V * sizeof(struct AdjList)); 
  
    // Initialize each adjacency list as empty by  
    // making head as NULL 
    int i; 
    for (i = 0; i < V; ++i) 
        graph->array[i].head = NULL; 
  
    return graph; 
} 
  
// Adds an edge to an undirected graph 
void addEdge(struct Graph* graph, int src, int dest) 
{ 
    // Add an edge from src to dest.  A new node is  
    // added to the adjacency list of src.  The node 
    // is added at the begining 
    struct AdjListNode* newNode = newAdjListNode(dest); 
    newNode->next = graph->array[src].head; 
    graph->array[src].head = newNode; 
  
    // Since graph is undirected, add an edge from 
    // dest to src also 
    newNode = newAdjListNode(src); 
    newNode->next = graph->array[dest].head; 
    graph->array[dest].head = newNode; 
} 
  
// A utility function to print the adjacency list  
// representation of graph 
void printGraph(struct Graph* graph) 
{ 
    int v; 
    for (v = 0; v < graph->V; ++v) 
    { 
        struct AdjListNode* pCrawl = graph->array[v].head; 
        printf("\n Adjacency list of vertex %d\n head ", v); 
        while (pCrawl) 
        { 
            printf("-> %d", pCrawl->dest); 
            pCrawl = pCrawl->next; 
        } 
        printf("\n"); 
    } 
} 

// int find_end(t_farm farm, char *line)
// {
// 	char **data;

// 	while(ft_strncmp(line, "##end", 5) != 0)
// 	{
// 		free(line);
// 		get_next_line(0, &line);
// 	}
// 	get_next_line(0, &line);
// 	data = ft_strsplit(line, ' ');
// 	farm.end = ft_atoi(data[0]);
// 	farm.coords_of_end.x = ft_atoi(data[1]);
// 	farm.coords_of_end.y = ft_atoi(data[2]);
// 	if (farm.start == farm.end)
// 		ft_error(2);
// 	printf("We are going to room %d coords x %d and y %d\n", farm.end, farm.coords_of_end.x, farm.coords_of_end.y);
// 	return (1);
// }

void	ft_error(int code)
{
	if (code == 1)
		ft_putendl ("Not enough ants, try again!");
	else if (code == 2)
		ft_putendl("The same start and end, not going to work!");
	exit(code);
}