#include <SFML/Audio.hpp>
#include <vector>



class musicClass
{
    public:
        // Constructor

        musicClass() : soundBuffer() 
        {
            /*LoadMusic();*/
        }
       
        
        ~musicClass() 
        {
           
        }
        // Crear un objeto sf::Sound para reproducir el sonido
        sf::Sound sound;

        

        


    


        void Play();
        void Stop();
        void LoadMusic();

    private:
    
        // Objeto sf::Music para gestionar la música
        sf::SoundBuffer soundBuffer;



};