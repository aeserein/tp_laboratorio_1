#ifndef FLOW_H_INCLUDED
#define FLOW_H_INCLUDED

/** \brief  Pausa el programa. Limpia la pantalla al continuar
 *
 * \param   void
 * \return  void
 */
void pausaYClear(void);

/** \brief  Pregunta algo al usuario
 *
 * \param   void
 * \return  int     -   1 para s�
 *                  -   0 para no
 */
unsigned short pregunta(char[]);

#endif
