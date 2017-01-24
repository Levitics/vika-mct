/*!
 *
 *  @copyright . (c) 2009-2016 PROJECT <http://www.exemple.org>
 *
 */
/*!
 * @file   CodingStyle.hpp
 * @brief  Brief description of file.
 *
 * Detailed description of file.
 *  @bug No known bugs.
 */

#ifndef PATH_TO_FOLDER_CODINGSTYLE_HPP
#define PATH_TO_FOLDER_CODINGSTYLE_HPP
/*!
 * @name    Example API Actions
 * @brief   Example actions available.
 * @ingroup example
 *
 * This API provides certain actions as an example.
 *
 * @param [in] repeat  Number of times to do nothing.
 *
 * @retval TRUE   Successfully did nothing.
 * @retval FALSE  Oops, did something.
 *
 * Example Usage:
 * @code
 *    example_nada(3); // Do nothing 3 times.
 * @endcode
 */
 
 /*! @bug The text explaining the bug */

/*!
 * @defgroup PackageName PackageTitle
 * @brief    T Provide some stuff to do stuff.
 *
 * @{
 */

/*!
 * @defgroup example_child1 First Child of Example
 * @brief    1st of 2 example children.
 */

/*!
 * @defgroup example_child2 Second Child of Example
 * @brief    2nd of 2 example children.
 * @}
 */

/*! 
 * Kernel include files come first.
 */

/*! Non-local includes in brackets. 
*/
/*!
* If it's a network program, put the network include files next.
* Group the includes files by subdirectory.
*/

/*!
* Then there's a blank line, followed by the /usr include files.
* The /usr include files should be sorted!
*/

#include <System/headers>
#include <3rtparty/headers>
#include <standard/library/headers>
#include <project/headers>

/*! 
 *  @class CodingStyle
 *  @brief     Pretty nice class.
 *  @details   This class is used to demonstrate a number of section commands.
 *  @pre       First initialize the system.
 *  @bug       Not all memory is freed when deleting an object of this class.
 *  @warning   Improper use can crash your application
 */
class CodingStyle 
{
	/*!
	 * @brief    Couleur possible pour un Point.
	 * @details  La table de correspondance de couleurs est disponible en modification par les accesseurs.
	 */	
    enum anEnumeration 
    {
        en = 0,  /*!< .... */
		fr,		/*!< .... */
		none	/*!< .... */
    };
    
public:
    /*! 
     * @brief default constructor.
     */    
    CodingStyle();                                              
    /*!
     * @brief copy constructor. 
     */    
    CodingStyle(const CodingStyle& orig) = default;             
    /*! 
     * @brief Move constructor  noexcept is deduced.
     */
    CodingStyle(CodingStyle&& orig) = default;
    /*! 
     * @brief Copy assignment: clean up target and copy  noexcept is deduced
     * @returns CodingStyle reference.
     */
    CodingStyle & operator=(const CodingStyle& orig) = default; 
    /*! 
     * @brief Move assignment: clean up target and move 
     * @returns CodingStyle reference.
     */
    CodingStyle & operator=(CodingStyle && orig) = default;     
    virtual ~CodingStyle() = default;
    /*!
     * @brief Change the internal value
     * 
     * @param Value const reference
     */
    void setValue( const type & value );
    /*!
     * @brief Returns the internal value for reading
     * 
     * @returns type const reference
     */
     type & getValue( void ) const;    
	/*! @brief Writes the current foreground and background
	 *         color of characters printed on the console
	 *         into the argument color.
	 *  @param color The address to which the current color
	 *         information will be written.
	 *  @return Void.
	 */
	void get_term_color(int* color);
    void publicMethod();
    /*! 
     *  @brief One-line summary of what the method does
     *
     *  Full description of what the method does
     *
     *  @tparam <T> A description of the template parameter
     *  @param[in] Parameter1 A description of the parameter
     *  @param[out] Parameter2 A description of the parameter
     *
     *  @return A description of the returned object
     */
  template<typename T>
  T MyFunction(int Parameter1, int& Parameter2);
  
protected:  // Not required if there are none.
	/*!
	 * @brief  Calcule la distance entre deux points
	 * @details La distance entre les @a point1 et @a point2 est calculée par l'intermédiaire
	 *           des coordonnées des points. (cf #Point)
	 * @param  point1 Point 1 pour le calcul de distance.
	 * @param  point2 Point 2 pour le calcul de distance.
	 * @return Un @e float représentant la distance calculée.
	 */
	 float distance(Pont points, Point point2);
    void protectedMethod();
private:    // Not required if there are none.
    void privateMethod();
    int member ;/*! A brief description */
};

#endif

