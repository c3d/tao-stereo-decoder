/**
 * @~english
 * @taomoduledescription{StereoDecoder, StereoDecoder}
 *
 * <tt>import StereoDecoder</tt> - Decode stereoscopic and multiview formats.\n
 *
 * This module allows you to decode some stereoscopic or multiscopic
 * formats of your different medias and convert it to the current Tao
 * display.
 * It currently supports the following video or picture formats:
 *     - HSPLIT: horizontal split mode, also known as side-by-side.
 *     - VSPLIT: vertical split mode, also known as top/bottom.
 *     - RHSPLIT: reversed horizontal split (since version 1.01)
 *     - RVSPLIT: reversed vertical split (since version 1.01)
 *     - 5VIEW: 5 view videos encoded in a single stream (since version 1.02)
 *     - 8VIEW: 8 view video encoded in a single stream (since version 1.02)
 *     - 2D+Z: 2D+Z format with separate color and depth map (since version 1.02)
 *     - Declipse: 2D+Z format with two separate color and depth map * 2 (since version 1.02)
 * For instance, the following code decode a video with a side-by-side
 * format in Tao.
 * @include stereo_decoder.ddd
 *
 * @endtaomoduledescription{StereoDecoder}
 *
 * @~french
 * @taomoduledescription{StereoDecoder, Décodeur stéréoscopique}
 *
 * <tt>import StereoDecoder</tt> - Décode des formats stéréoscopiques et multi-vues.\n
 *
 * Ce module vous permet de décoder certains formats d'images ou de vidéos
 * stéréoscopiques, de manière à les afficher correctement dans
 * Tao Presentations.
 * Ce module supporte les fomats d'image ou de vidéo suivants:
 *     - HSPLIT : partage horizontal (<em>horizontal split</em>), également
 *       appelé côte-à-côte (<em>side-by-side</em>).
 *     - VSPLIT : partage vertical (<em>vertical split</em>), également
 *       appelé dessus/dessous (<em>top/bottom</em>).
 *     - RHSPLIT : partage horizontal inversé (à partir de la version 1.01)
 *     - RVSPLIT : partage vertical inversé (à partir de la version 1.01)
 *     - 5VIEW: format à 5 imqges encodées dans une trame (à partir de la version 1.02)
 *     - 8VIEW: format à 8 images encodées dans une trame (à partir de la version 1.02)
 *     - 2D+Z: format 2D+Z avec carte couleur et profondeur séparées (à partir de la version 1.02)
 *     - Declipse: format 2D+Z avec double carte de couleur et de profondeur (à partir de la version 1.02)
 * L'exemple qui suit montre comment décoder une vidéo au format côte-à-côte
 * (<em>side-by-side</em>). Le document s'affichera correctement quel que soit
 * le mode d'affichage choisi dans Tao Presentations : côte-à-côte,
 * dessus/dessous (<em>over/under</em>), entrelacé (<em>interleaved</em>)...
 * ou même, simplement, 2D.
 * @include stereo_decoder.ddd
 *
 * @endtaomoduledescription{StereoDecoder}
 *
 * @~
 * @{
 */

/**
 * @~english
 * Decode horizontal split format.
 * Decode the horizontal split format, also known as side-by-side format.
 *
 * This function is equivalent to the following code:
 * @~french
 * Décode le format partage horizontal.
 * Équivalent à :
 * @~
 @code
decode_stereo "HSPLIT", texture_width, texture_height
 @endcode
 */
decode_horizontal_split();

/**
 * @~english
 * Decode reversed horizontal split format.
 * Decode the horizontal split format, also known as side-by-side format.
 * This assumes that the left and right eye are reversed.
 *
 * This function is equivalent to the following code:
 * @~french
 * Décode le format partage horizontal inversé.
 * Équivalent à :
 * @~
 @code
decode_stereo "RHSPLIT", texture_width, texture_height
 @endcode
 * @since 1.01
 */
decode_horizontal_split_reverse();

/**
 * @~english
 * Decode vertical split format.
 * Decode the vertical split format, also known as over/under format.
 *
 * This function is equivalent to the following code:
 * @~french
 * Décode le format partage vertical.
 * Équivalent à :
 * @~
 @code
 decode_stereo "VSPLIT", texture_width, texture_height
 @endcode
 */
decode_vertical_split();

/**
 * @~english
 * Decode reversed vertical split format.
 * Decode the vertical split format, also known as over/under format.
 * This assumes that left and right eye are reversed.
 *
 * This function is equivalent to the following code:
 * @~french
 * Décode le format partage vertical.
 * Équivalent à :
 * @~
 @code
 decode_stereo "RVSPLIT", texture_width, texture_height
 @endcode
 * @since 1.01
 */
decode_vertical_split_reverse();

/**
 * @~english
 * Apply a stereoscopic decoding on the current texture.
 * Decode the current texture with the stereoscopic @p mode and
 * redraw it with the size (@p w, @p h).
 *
 * @~french
 * Effectue le décodage stéréoscopique de la texture courante.
 *
 * Décode la texture courante en supposant qu'elle est encodée
 * avec le mode @p mode, et affiche la vue adaptée
 * sous forme d'un rectangle de taille (@p w, @p h).
 */
decode_stereo(mode:text, w:integer, h:integer);

/**
 * @~english
 * Draw only for the specified stereoscopic point of views.
 *
 * @p viewpoints is a bitmask that specifies for which eyes the
 * drawing should take place.
 *
 * Viewpoints are numbered from left to right. When there are no more
 * that two viewpoints, 1 is the left eye and 2 the right eye so that:
 *
 * - left_viewpoint is synonym for <tt>stereo_viewpoints 1</tt>.
 * - right_viewpoint is synonym for <tt>stereo_viewpoints 2</tt>.
 *
 * The following example shows a square to the left eye and a circle
 * to the right eye (such code may be used to check if a stereoscopic
 * setup works properly):
 * @~french
 * Affiche seulement sur certains points de vue stéréoscopiques.
 *
 * @p viewpoints est un masque de bits qui précise pour quels points
 * de vue il faut dessiner.
 *
 * Les points de vue sont numérotés de gauche à droite. Lorsqu'il y a seulement
 * deux points de vue (stéréoscopie simple), l'œil gauche porte le numéro 1 et
 * l'œil droit a le numéro 2, donc :
 *
 * - left_viewpoint est synonyme de <tt>stereo_viewpoints 1</tt>.
 * - right_viewpoint est synonyme de <tt>stereo_viewpoints 2</tt>.
 *
 * L'exemple qui suit montre un carré à l'œil gauche et un cercle à l'œil
 * droit (ce qui peut être utile pour s'assurer qu'une configuration
 * stéréoscopique fonctionne correctement) :
 * @~
@code
clear_color 0, 0, 0, 0
color "white"
left_viewpoint
    rectangle 0, 0, 100, 100
right_viewpoint
    circle 0, 0, 50
text_box 0, 0, window_width, window_height,
    align_center
    vertical_align_bottom
    font "Andika Basic", 40
    color "white"
    text "Left eye: square     Right eye: circle"
@endcode
 * @~english
 * @note This primitive only affects the drawing phase, not the execution
 * phase. In other words, the code guarded by stereo_viewpoints is
 * always executed, whatever the value @p viewpoints may be. In that
 * respect, the stereo_viewpoint primitive behaves pretty much like
 * @p locally. It is only during the drawing phase that conditional
 * drawing occurs.
 * @~french
 * @note Cette primitive n'affecte que la phase d'affichage pas l'exécution.
 * En d'autres termes, le code protégé par @ref stereo_viewpoints est toujours
 * exécuté, quelle que soit la valeur de @p viewpoints. En ce sens, la
 * primitive se comporte comme @p locally, et c'est seulement lors de la
 * phase d'affichage que le tracé est conditionné au point de vue en cours
 * de tracé.
 */
stereo_viewpoints(viewpoints:integer);

/**
 * @~english
 * Draw only for the left eye.
 * Equivalent to:
 * @~french
 * Affiche seulement pour l'œil gauche.
 * Équivalent à :
 * @~
 * @code stereo_viewpoints 1 @endcode
 */
left_viewpoint(B:block);

/**
 * @~english
 * Draw only for the right eye.
 * Equivalent to:
 * @~french
 * Affiche seulement pour l'œil droie.
 * Équivalent à :
 * @~
 * @code stereo_viewpoints 2 @endcode
 */
right_viewpoint(B:block);

/**
* @}
*/
