/**
 * @~english
 * @taomoduledescription{StereoDecoder, StereoDecoder}
 * <tt>import StereoDecoder</tt> - Decode stereoscopic and multiview formats.@n
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
 * <tt>import StereoDecoder</tt> - Décode des formats stéréoscopiques et multi-vues.@n
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
 * @~english
 * Decode a multi-stream movie
 * Decode a movie that is encoded with multiple video streams. This format
 * is presently supported in containers such as MP4, and requires a specific
 * version of VLC.
 *
 * The @p Movie parameter specifies the URL of the movie to play.
 * The @p LeftIndex parameter indicates the index of stream for the leftmost
 * picture.
 * The @p Increment parameter indicates the increment from one stream to the
 * next.
 * For example, if you have eight streams with stream 0 representing
 * the leftmost picture, set @p LeftIndex to 0 and @p Increment to 1.
 * If stream 0 represents the rightmost pictures, set @p LeftIndex to 7
 * and @p Increment to -1.
 *
 * @~french
 * Decode un film en format multi-flux
 * Decode un film encodé dans un format multiflux. Ce format est
 * supporté pour le moment avec certains containers comme MP4, et
 * requiert une version spécifique de VLC.
 *
 * Le paramètre @p Movie indique l'URL du film à jouer.
 * Le paramètre @p LeftIndex indique l'index du flux contenant les
 * images les plus à gauche. Le paramètre @p Increment représente la
 * différence d'index d'un flux au suivant.
 * Par exemple, si vous avez 8 flux et que le flux 0 représente
 * l'image la plus à gauche, mettez @p LeftIndex à 0 et @p Increment à 1.
 * Au contraire, si le flux 0 est l'image la plus à droite, mettez
 * @p LeftIndex à 7 et @p Increment à -1
 */
multistream_movie(Movie:text, LeftIndex:integer, Increment:integer);

/**
 * @~english
 * Decode sequence of pictures in multview format
 * Decode a sequence of pictures interpreted as multiple viewpoints
 * for the same multiscopic image.
 *
 * The @p Picture parameter specifies the URL of the pictures. It
 * should contain the '#' character, that will be replaced with a
 * picture index.
 * The @p LeftIndex parameter indicates the index of stream for the leftmost
 * picture.
 * The @p Increment parameter indicates the increment from one stream to the
 * next.
 * For example, if you have eight pictures names 'view1.png' through
 * 'view8.png' where 'view1.png' is the rightmost picture, you should
 * use @code multiview_image "view#.png", 8, -1 @encode.
 *
 * @~french
 * Decode une sequence d'images en multiscopie
 * Decode une séquence d'images interprétées comme les différents
 * points de vue d'une même image multiscopique.
 *
 * Le paramètre @p Picture indique l'URL des images à jouer. Cette URL
 * devrait contenir le caractère "#" qui sera remplacé par le numéro
 * de la vue.
 * Le paramètre @p LeftIndex indique l'index du flux contenant les
 * images les plus à gauche. Le paramètre @p Increment représente la
 * différence d'index d'un flux au suivant.
 * Par exemple, si vous avez 8 images où "image1.png" est l'image la
 * plus à droite et "image8.png" l'image la plus à droite, utilisez
 * @code multiview_image "image#.png", 8, -1 @endcode
 */
multiview_image(Picture:text, LeftIndex:integer, Increment:integer);



/**
* @}
*/
