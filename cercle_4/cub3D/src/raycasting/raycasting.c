/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terijo <terijo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:12:00 by daavril           #+#    #+#             */
/*   Updated: 2025/05/07 02:18:29 by terijo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

/**
 * @brief   Get the direction of the ray
 *
 * @param   game struct of the game
 * @param   x    the pixel
 *
 * @return
 */
void    ft_get_ray_dir(t_game *game, int x)
{
    double  camera_x;

    game->ray->map_x = (int)game->player->p_x;
    game->ray->map_y = (int)game->player->p_y;
    //la position horizontale du rayon sur le plan de la caméra
    camera_x = 2 * x / (double)WIN_WIDTH - 1;
    //calcul pour avoir la direction en x et en y du rayon
    game->ray->ray_dir_x = game->player->dir_x + game->player->plane_x * camera_x;
    game->ray->ray_dir_y = game->player->dir_y + game->player->plane_y * camera_x;
}

/**
 * @brief   Get the distance between each line with the ray at x pixel
 *
 * @param   game struct of the game
 *
 * @return
 */
void    ft_get_delta_dist(t_game *game)
{
    //distance entre deux lignes verticales traversées par le rayon
    game->ray->delta_dist_x = fabs(1 / game->ray->ray_dir_x);
    //distance entre deux lignes horizontales traversées par le rayon
    game->ray->delta_dist_y = fabs(1 / game->ray->ray_dir_y);
}

/**
 * @brief   
 *
 * @param   game struct of the game
 *
 * @return
 */
void    ft_get_step_and_side_dist(t_game *game)
{
   t_player *p;
   t_ray    *ray;

   p = game->player;
   ray = game->ray;
   if (ray->ray_dir_x < 0)
   {
       //on va à gauche dans la grille
       ray->step_x = -1;
       //calcul la dist que doit parcourrir le rayon pour la prochaine ligne à gauche
       ray->side_dist_x = (p->p_x - ray->map_x) * ray->delta_dist_x;
   }
   else
   {
       //on va à droite dans la grille
       ray->step_x = 1;
       //calcul la dist que doit parcourrir le rayon pour la prochaine ligne à droite
       ray->side_dist_x = (ray->map_x + 1.0 - p->p_x) * ray->delta_dist_x;
   }
   if (ray->ray_dir_y < 0)
   {
       //on monte dans la grille
       ray->step_y = -1;
       //calcul la dist que doit parcourrir le rayon pour la prochaine ligne en haut
       ray->side_dist_y = (p->p_y - ray->map_y) * ray->delta_dist_y;
   }
   else
   {
       //on descend dans la grille
       ray->step_y = 1;
       //calcul la dist que doit parcourrir le rayon pour la prochaine ligne en bas
       ray->side_dist_y = (ray->map_y + 1.0 - p->p_y) * ray->delta_dist_y;
   }
}

/**
 * @brief   Make the ray go forward until it touches a wall
 *
 * @param   game struct of the game
 *
 * @return
 */
 void    ft_dda(t_game *game)
{
    int hit;
    t_ray *ray;
    
    hit = 0;
    ray = game->ray;
    while (!hit)
	{
		// avance dans la grille
        if (ray->side_dist_x < ray->side_dist_y)
        {
            //le rayon avance d'une unité de deplacement en x
            ray->side_dist_x += ray->delta_dist_x;
            //la position de depart du rayon se deplace de une unité en x
            ray->map_x += ray->step_x;
            //on enregistre quel coté du mur on a touché, ici coté vertical
            ray->side = 0;
        }
        else
        {
            //le rayon avance d'une unité de deplacement en y
            ray->side_dist_y += ray->delta_dist_y;
            //la position de depart du rayon se deplace de une unité en y
            ray->map_y += ray->step_y;
            //on enregistre quel coté du mur on a touché, ici coté horizontal
            ray->side = 1;
        }
        //si on rencontre un mur alors on sort
		if (game->map[ray->map_y][ray->map_x] == '1')
            hit = 1;
	}
}

/**
 * @brief  
 *
 * @param   game struct of the game
 *
 * @return
 */
void    ft_compute_wall_height(t_game *game, int x)
{
    t_player *player;
    t_ray    *ray;

    player = game->player;
    ray = game->ray;
    //calcul de la distance entre le mur (map_) et le joueur (p_)
    if (ray->side == 0)
        ray->wall_dist = (ray->map_x - player->p_x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
    else
        ray->wall_dist = (ray->map_y - player->p_y + (1 - ray->step_y) / 2) / ray->ray_dir_y;
    //calcul de la hauteur du mur a dessiner
    ray->line_height = (int)(WIN_HEIGHT / ray->wall_dist);
    //on determine où on commence/arrete de dessiner la ligne verticale en partant du milieu de la ligne
    ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
    if (ray->draw_start < 0) //on bloque le start à 0 si on est tres proche du mur
        ray->draw_start = 0;
    ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
    if (ray->draw_end >= WIN_WIDTH)
        ray->draw_end = WIN_WIDTH - 1;
    //calcul de la zone d'impact du rayon sur le mur(à gauche, au centre ou à droite du mur)
    //besoin pour savoir quelle colonne de pixel de la texture on veut afficher pour la colonne x de l'ecran
    if (ray->side == 0)
        ray->wall_x = player->p_y + ray->wall_dist * ray->ray_dir_y;
    else
        ray->wall_x = player->p_x + ray->wall_dist * ray->ray_dir_x;
    ray->wall_x -= floor(ray->wall_x);//permet de garder que la partie decimale(entre 0 et 1)
}

/**
 * @brief   Raycasting engine
 *
 * @param   game struct of the game
 *
 * @return
 */
int	ft_raycasting(t_game *game)
{
	int	x;

	x = 0;
    ft_init_splayer(game);
    /*
    *Tu pourrais centraliser toutes les variables de raycasting (position, rayons, distances, steps, etc.) 
    *dans un seul t_ray, comme tu le fais déjà, mais attention à ne pas faire de ce t_ray un singleton global. 
    *Il serait plus robuste d’avoir un tableau de t_ray par colonne x si tu fais des effets futurs 
    *comme des sprites, des ombres ou des portails.
    */
	while (x < WIN_WIDTH)
	{
        ft_get_ray_dir(game, x);
        ft_get_delta_dist(game);
        ft_get_step_and_side_dist(game);
        ft_dda(game);
        ft_compute_wall_height(game, x);
		x++;
	}
    // Affichage / Dessin
    // Il ne te manque plus qu’une étape pour afficher l’image à l’écran : 
    // utiliser draw_start, draw_end, x, et la texture (ou une simple couleur unie pour l’instant). 
    // Tu pourras dessiner une ligne verticale avec mlx_pixel_put ou mieux, directement écrire dans une image buffer.
	return (0);
}
