import java.util.ArrayList;

public class Empresa
{
    private String cnpj;
    private String nome;
    private String telefone;
    
    private ArrayList<Usuario> clientes;
    private ArrayList<App> catalogoApps;
    
    public Empresa (String cnpj, String nome, String telefone) {
        this.cnpj = cnpj;
        this.nome = nome;
        this.telefone = telefone;
        
        this.clientes = new ArrayList<>();
        this.catalogoApps = new ArrayList<>();
    }
    
    public void cadastrarUsuario(Usuario novoUsuario) {
        clientes.add(novoUsuario);
    }
    
    public String getNome () {
        return this.nome;
    }
    
    public void avaliarGastoMensal (Usuario user, App appSugerido) {
        boolean podeReduzir = false;
        
        for (App appAvaliado : user.getMeusApps()) {
            if (appAvaliado.substituir (appSugerido) == true) {
                System.out.println("O usuário, " + user + ", pode trocar o app " + appAvaliado.getNomeApp() + 
                                   " pelo app " + appSugerido.getNomeApp() + " para economizar.");
                podeReduzir = true;
            }
        }
        
        if (!podeReduzir) {
            System.out.println("O usuário não pode economizar.");
        }
        
    }
    
    public void adicionarAppAoCatalogo(App novoApp) {
        catalogoApps.add(novoApp);
    }
    
    public String appMaisUsado() {
        App appCampeao = null;
        int maiorContagem = -1;
    
        for (App appNoCatalogo : catalogoApps) {
            int contadorDeUsuarios = 0;
    
            for (Usuario u : clientes) {
                if (u.getMeusApps().contains(appNoCatalogo)) {
                    contadorDeUsuarios++;
                }
            }
    
            if (contadorDeUsuarios > maiorContagem) {
                maiorContagem = contadorDeUsuarios;
                appCampeao = appNoCatalogo;
            }
        }
    
        return (appCampeao != null) ? appCampeao.getNomeApp() : "Nenhum app usado";
    }
    
}