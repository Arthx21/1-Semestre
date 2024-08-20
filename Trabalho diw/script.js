window.albumId;
window.conteudodestaque;
window.destacar;

document.addEventListener('DOMContentLoaded', function () {
    const conteudoalbum = document.getElementById('albuns');

    

    fetch('https://66c94b44-8a3d-44cb-a9bb-700f323315de-00-lq5icdtpt2km.picard.replit.dev/estruturamapa')
        .then(response => {
            if (!response.ok) {
                throw new Error(`Erro ao carregar o arquivo JSON: ${response.status}`);
            }
            return response.json();
        })
        .then(estruturamapa => {

            estruturamapa.forEach(uni => {
                const estruturamapaHTML = `
                      <div class="album">
                          <a href="detalhedoalbum.html?id=${uni.id}"><img src="${uni.url}" class="imagens" alt=""></a>
                          <h6>${uni.nome}</h6>
                          <p>${uni.descricao}</p>
                          <p>${uni.data}</p>
                          <a href="detalhedoalbum.html?id=${uni.id}" class="visualizar">Visualizar Álbum</a>
                          <button class="visualizar" onclick="destacar(${uni.id})">Destacar</button>
                      </div>`;
                conteudoalbum.innerHTML += estruturamapaHTML;


            });
        })
        .catch(error => console.error('Erro ao obter as Estruturas:', error));
});

document.addEventListener('DOMContentLoaded', function () {


    fetch('https://66c94b44-8a3d-44cb-a9bb-700f323315de-00-lq5icdtpt2km.picard.replit.dev/estruturamapa')
        .then(response => {
            if (!response.ok) {
                throw new Error(`Erro ao carregar o arquivo JSON: ${response.status}`);
            }
            return response.json();
        })
        .then(estruturamapa => {

            const centralLatLong = [-95.664300, 38.9385]

            mapboxgl.accessToken = 'pk.eyJ1IjoiYXJ0aDIxIiwiYSI6ImNscDh1b3V1eDAyeGYycW81ZmpxMWwxNjgifQ.PASLLblI-czFF4TwOt0oXw';
            const map = new mapboxgl.Map({
                container: 'map',
                style: 'mapbox://styles/mapbox/streets-v12',
                center: centralLatLong,
                zoom: 3.5
            });

            estruturamapa.forEach((uni) => {
                var popup = new mapboxgl.Popup({ offset: 25 })
                    .setHTML(`<h3><a href="" target="_blank">${uni.nome}</a></h3><br>${uni.latlong}`);
                const marker = new mapboxgl.Marker({ color: 'red' })
                    .setLngLat(uni.latlong)
                    .setPopup(popup)
                    .addTo(map);
            });
        })
});

document.addEventListener('DOMContentLoaded', function () {
    window.conteudodestaque = document.getElementById('destaque');

    fetch('https://66c94b44-8a3d-44cb-a9bb-700f323315de-00-lq5icdtpt2km.picard.replit.dev/estruturamapa')
        .then(response => {
            if (!response.ok) {
                throw new Error(`Erro ao carregar o arquivo JSON: ${response.status}`);
            }
            return response.json();
        })
        .then(estruturamapa => {

            conteudodestaque.innerHTML = `
            <div>
            <div id="carouselExampleIndicators" class="carousel slide">
              <div class="carousel-indicators">
             <button type="button" data-bs-target="#carouselExampleIndicators" data-bs-slide-to="0" class="active" aria-current="true" aria-label="Slide 1"></button>
            <button type="button" data-bs-target="#carouselExampleIndicators" data-bs-slide-to="1" aria-label="Slide 2"></button>
              <button type="button" data-bs-target="#carouselExampleIndicators" data-bs-slide-to="2" aria-label="Slide 3"></button>
             </div>
              <div class="carousel-inner">
                  <div class="carousel-item active">
                     <img src="imagens/novayork.jpg" class="d-block w-100" style="object-fit: cover; height: 500px;" alt="...">
                  </div>
                  <div class="carousel-item">
                     <img src="imagens/golden-gate-bridge-1-770x515.jpg" class="d-block w-100" style="object-fit: cover; height: 500px;" alt="...">
                  </div>
                  <div class="carousel-item">
                      <img src="imagens/miami.jpg" class="d-block w-100" style="object-fit: cover; height: 500px;" alt="...">
                 </div>
            </div>
               <button class="carousel-control-prev" type="button" data-bs-target="#carouselExampleIndicators" data-bs-slide="prev">
               <span class="carousel-control-prev-icon" aria-hidden="true"></span>
               <span class="visually-hidden">Previous</span>
     </button>
             <button class="carousel-control-next" type="button" data-bs-target="#carouselExampleIndicators" data-bs-slide="next">
               <span class="carousel-control-next-icon" aria-hidden="true"></span>
              <span class="visually-hidden">Next</span>
                 </button>
            </div>
            </div>
            `;

        })
});


document.addEventListener('DOMContentLoaded', function () {
    const urlParams = new URLSearchParams(window.location.search);
    albumId = urlParams.get('id');


    // Verificar se o ID do álbum é válido
    if (albumId) {
        const detalhesAlbum = document.getElementById('detalhesAlbum');
        const fotosAlbumElement = document.getElementById('fotosAlbum');
        const botaodestaque = document.getElementById('botaodestaque');

        // Fazer uma solicitação fetch para obter detalhes do álbum específico com base no ID
        fetch(`https://66c94b44-8a3d-44cb-a9bb-700f323315de-00-lq5icdtpt2km.picard.replit.dev/estruturamapa/${albumId}`)
            .then(response => {
                if (!response.ok) {
                    throw new Error(`Erro ao carregar detalhes do álbum: ${response.status}`);
                }
                return response.json();
            })
            .then(album => {


                // Exibir os detalhes do álbum no DOM
                detalhesAlbum.innerHTML = `
                        <img src="${album.url}" class="imagemAlbum">
                        <div class="textoAlbum">
                            <h6>Descrição</h6>
                            <p>${album.descricao}</p>
                            <div class="localizacao">
                                <h6>Localização</h6>
                                <p>${album.latlong}</p>
                            </div>
                            <div class="dataderegistro">
                                <h6>Data de Registro</h6>
                                <p>${album.data}</p>
                            </div>
                        </div>`;
            })
            .then(() => {

                if (albumId == 1) {
                    for (let idalbum = 1; idalbum <= 8; idalbum++) {
                        fetch(`https://66c94b44-8a3d-44cb-a9bb-700f323315de-00-lq5icdtpt2km.picard.replit.dev/fotosnovayork/${idalbum}`)
                            .then(response => {
                                if (!response.ok) {
                                    throw new Error(`Erro ao carregar foto do álbum: ${response.status}`);
                                }
                                return response.json();
                            })
                            .then(data => {
                                // Adicione cada foto como um card
                                adicionarCardFoto(fotosAlbumElement, data);
                            })
                            .catch(error => console.error(`Erro ao obter foto do álbum ${idFoto}:`, error));

                    }


                }//fim do for // e do meu if


                if (albumId == 2) {
                    for (let idalbum = 9; idalbum <= 16; idalbum++) {
                        fetch(`https://66c94b44-8a3d-44cb-a9bb-700f323315de-00-lq5icdtpt2km.picard.replit.dev/fotosnovayork/${idalbum}`)
                            .then(response => {
                                if (!response.ok) {
                                    throw new Error(`Erro ao carregar foto do álbum: ${response.status}`);
                                }
                                return response.json();
                            })
                            .then(data => {
                                // Adicione cada foto como um card
                                adicionarCardFoto(fotosAlbumElement, data);
                            })
                            .catch(error => console.error(`Erro ao obter foto do álbum ${idFoto}:`, error));
                    }

                }//fim do for // e do meu if


                if (albumId == 3) {
                    for (let idalbum = 17; idalbum <= 24; idalbum++) {
                        fetch(`https://66c94b44-8a3d-44cb-a9bb-700f323315de-00-lq5icdtpt2km.picard.replit.dev/fotosnovayork/${idalbum}`)
                            .then(response => {
                                if (!response.ok) {
                                    throw new Error(`Erro ao carregar foto do álbum: ${response.status}`);
                                }
                                return response.json();
                            })
                            .then(data => {
                                // Adicione cada foto como um card
                                adicionarCardFoto(fotosAlbumElement, data);
                            })
                            .catch(error => console.error(`Erro ao obter foto do álbum ${idFoto}:`, error));
                    }
                }//fim do for // e do meu if

                if (albumId == 4) {
                    for (let idalbum = 25; idalbum <= 32; idalbum++) {
                        fetch(`https://66c94b44-8a3d-44cb-a9bb-700f323315de-00-lq5icdtpt2km.picard.replit.dev/fotosnovayork/${idalbum}`)
                            .then(response => {
                                if (!response.ok) {
                                    throw new Error(`Erro ao carregar foto do álbum: ${response.status}`);
                                }
                                return response.json();
                            })
                            .then(data => {
                                // Adicione cada foto como um card
                                adicionarCardFoto(fotosAlbumElement, data);
                            })
                            .catch(error => console.error(`Erro ao obter foto do álbum ${idFoto}:`, error));
                    }
                }//fim do for // e do meu if

                if (albumId == 5) {
                    for (let idalbum = 33; idalbum <= 40; idalbum++) {
                        fetch(`https://66c94b44-8a3d-44cb-a9bb-700f323315de-00-lq5icdtpt2km.picard.replit.dev/fotosnovayork/${idalbum}`)
                            .then(response => {
                                if (!response.ok) {
                                    throw new Error(`Erro ao carregar foto do álbum: ${response.status}`);
                                }
                                return response.json();
                            })
                            .then(data => {
                                // Adicione cada foto como um card
                                adicionarCardFoto(fotosAlbumElement, data);
                            })
                            .catch(error => console.error(`Erro ao obter foto do álbum ${idFoto}:`, error));
                    }
                }//fim do for // e do meu if

                if (albumId == 6) {
                    for (let idalbum = 41; idalbum <= 48; idalbum++) {
                        fetch(`https://66c94b44-8a3d-44cb-a9bb-700f323315de-00-lq5icdtpt2km.picard.replit.dev/fotosnovayork/${idalbum}`)
                            .then(response => {
                                if (!response.ok) {
                                    throw new Error(`Erro ao carregar foto do álbum: ${response.status}`);
                                }
                                return response.json();
                            })
                            .then(data => {
                                // Adicione cada foto como um card
                                adicionarCardFoto(fotosAlbumElement, data);
                            })
                            .catch(error => console.error(`Erro ao obter foto do álbum ${idFoto}:`, error));
                    }
                }//fim do for // e do meu if

                if (albumId == 7) {
                    for (let idalbum = 49; idalbum <= 56; idalbum++) {
                        fetch(`https://66c94b44-8a3d-44cb-a9bb-700f323315de-00-lq5icdtpt2km.picard.replit.dev/fotosnovayork/${idalbum}`)
                            .then(response => {
                                if (!response.ok) {
                                    throw new Error(`Erro ao carregar foto do álbum: ${response.status}`);
                                }
                                return response.json();
                            })
                            .then(data => {
                                // Adicione cada foto como um card
                                adicionarCardFoto(fotosAlbumElement, data);
                            })
                            .catch(error => console.error(`Erro ao obter foto do álbum ${idFoto}:`, error));
                    }
                }//fim do for // e do meu if

                if (albumId == 8) {
                    for (let idalbum = 57; idalbum <= 64; idalbum++) {
                        fetch(`https://66c94b44-8a3d-44cb-a9bb-700f323315de-00-lq5icdtpt2km.picard.replit.dev/fotosnovayork/${idalbum}`)
                            .then(response => {
                                if (!response.ok) {
                                    throw new Error(`Erro ao carregar foto do álbum: ${response.status}`);
                                }
                                return response.json();
                            })
                            .then(data => {
                                // Adicione cada foto como um card
                                adicionarCardFoto(fotosAlbumElement, data);
                            })
                            .catch(error => console.error(`Erro ao obter foto do álbum ${idFoto}:`, error));
                    }
                }//fim do for // e do meu if
            })
            .catch(error => console.error('Erro ao obter detalhes do álbum:', error));

    } //outro if

    function adicionarCardFoto(elementoPai, foto) {
        // Adiciona a foto como card
        elementoPai.innerHTML += `
        <div class="card">
        <img src="${foto.url}" class="card-img-top" alt="${foto.titulofoto}" onclick="openPopup('${foto.url}')">
        <div class="card-body">
            <h5 class="card-title">${foto.titulofoto}</h5>
        </div>
    </div>`;
    }
});




function openPopup(imageSrc) {
    var popup = document.getElementById('image-popup');
    var popupImage = document.getElementById('popup-image');

    // Define a imagem do popup
    popupImage.src = imageSrc;

    // Exibe o popup
    popup.style.display = 'flex';
}

// Função para fechar o popup
function closePopup() {
    var popup = document.getElementById('image-popup');
    popup.style.display = 'none';
}

document.addEventListener("DOMContentLoaded", function () {
    window.destacar = function declarar(albumId) {
        window.conteudodestaque = document.getElementById('destaque');

        window.scrollTo({
            top: 0,
            behavior: 'smooth'
        });


        fetch('https://66c94b44-8a3d-44cb-a9bb-700f323315de-00-lq5icdtpt2km.picard.replit.dev/fotosnovayork')
            .then(response => {
                if (!response.ok) {
                    throw new Error(`Erro ao carregar o arquivo JSON: ${response.status}`);
                }
                return response.json();
            })
            .then(fotosnovayork => {
                if (conteudodestaque) {
                    console.log('Fotos do servidor:', fotosnovayork);

                    // Limitando para exibir apenas as três primeiras imagens
                    switch (albumId) {
                        case 1:
                            tresPrimeirasFotos = fotosnovayork.slice(0, 3);
                            break;
                        case 2:
                            tresPrimeirasFotos = fotosnovayork.slice(8, 11);
                            break;
                        case 3:
                            tresPrimeirasFotos = fotosnovayork.slice(17, 20);
                            break;
                        case 4:
                            tresPrimeirasFotos = fotosnovayork.slice(25, 28);
                            break;
                        case 5:
                            tresPrimeirasFotos = fotosnovayork.slice(33, 36);
                            break;
                        case 6:
                            tresPrimeirasFotos = fotosnovayork.slice(41, 44);
                            break;
                        case 7:
                            tresPrimeirasFotos = fotosnovayork.slice(49, 52);
                            break;
                        case 8:
                            tresPrimeirasFotos = fotosnovayork.slice(59, 62);
                            break;
                        // Adicione os outros casos conforme necessário
                        default:
                            tresPrimeirasFotos = fotosnovayork.slice(0, 3);
                    }
                    conteudodestaque.innerHTML = ``;
                    conteudodestaque.innerHTML = `
                <div>
                    <div id="carouselExampleIndicators" class="carousel slide">
                        <div class="carousel-indicators">
                            ${tresPrimeirasFotos.map((foto, index) => `
                                <button type="button" data-bs-target="#carouselExampleIndicators" data-bs-slide-to="${index}" ${index === 0 ? 'class="active"' : ''} aria-label="Slide ${index + 1}"></button>
                            `).join('')}
                        </div>
                        <div class="carousel-inner">
                            ${tresPrimeirasFotos.map((foto, index) => `
                                <div class="carousel-item ${index === 0 ? 'active' : ''}">
                                    <img src="${foto.url}" class="d-block w-100" style=" height: 500px;" alt="Foto ${index + 1}">
                                </div>
                            `).join('')}
                        </div>
                        <button class="carousel-control-prev" type="button" data-bs-target="#carouselExampleIndicators" data-bs-slide="prev">
                            <span class="carousel-control-prev-icon" aria-hidden="true"></span>
                            <span class="visually-hidden">Previous</span>
                        </button>
                        <button class="carousel-control-next" type="button" data-bs-target="#carouselExampleIndicators" data-bs-slide="next">
                            <span class="carousel-control-next-icon" aria-hidden="true"></span>
                            <span class="visually-hidden">Next</span>
                        </button>
                    </div>
                </div>`;
                } else {
                    console.error('Elemento "destaque" não encontrado.');
                }
            })
            .catch(error => {
                console.error('Erro ao buscar fotos:', error);
            });

    }
})


function fundo() {
    const footer = document.getElementById('footer');
    footer.scrollIntoView({
      
        behavior: 'smooth'
    });
}

function meio() {
    const albu = document.getElementById('albuns');
    albu.scrollIntoView({
      
        behavior: 'smooth'
    });
}
 
function subir() {
    const mapi = document.getElementById('map');
    mapi.scrollIntoView({
        
        behavior: 'smooth'
    });
}
 