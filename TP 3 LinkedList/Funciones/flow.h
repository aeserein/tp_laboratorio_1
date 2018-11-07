#ifndef FLOW_H_INCLUDED
#define FLOW_H_INCLUDED

/** \brief  Pausa el programa. Limpia la pantalla al continuar
 *
 * \param   void
 * \return  void
 */
void pausaYClear(void);

/** \brief  Pregunta algo usuario
 *
 * \param   void
 * \return  int     -   1 si contin�a
 *                  -   0 si no contin�a
 */
unsigned short pregunta(char texto[50]);

/** \brief  Baja el cursor una l�nea
 *
 * \return void
 */
void renglon(void);

#endif
