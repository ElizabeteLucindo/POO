using Godot;
using System;

public partial class jogadorFireboy : CharacterBody2D
{
	private Vector2 direcao;
	[Export] private float velocidade = 150;
	[Export] private float gravidade = 100;
	[Export] private float altura_pulo = -4;
	public int pontuacao { get; private set; } = 0;
	private bool pulo_duplo;
	private bool puloNaParede = false;
	private bool podePularCoiote = true;
	private Timer tempoCoiote;
	
	public override void _Ready(){
		tempoCoiote = GetNode<Timer>("CoioteTimer");   
	}
	
	public override void _PhysicsProcess(double delta) 	{
		//Direcao
		if (Input.IsActionPressed("direita")) {
			direcao.X = 1;
		}else if (Input.IsActionPressed("esquerda")) {
			direcao.X = -1;
		} else {
			direcao.X=0;
		}
		
		//Recarregar pulo duplo
		if (IsOnFloor()) {
			pulo_duplo = true;
			podePularCoiote = true;
			puloNaParede = false;
			
		}else{ //Não está no ar
			direcao.Y = direcao.Y + 0.25f;
			// Ativar timer se podePularCoiote e o timer está parado
			if (podePularCoiote && tempoCoiote.IsStopped() ){
				tempoCoiote.Start(); // Inicia o timer
			}
		}
		
		//Pulo normal
		if (Input.IsActionJustPressed("pula") && (IsOnFloor() || podePularCoiote)) {
			direcao.Y = altura_pulo;
			podePularCoiote = false;
		}
		//Pulo duplo
		if (Input.IsActionJustPressed("pula") && !IsOnFloor() && pulo_duplo) {
			direcao.Y = altura_pulo;
			pulo_duplo = false;
		}
		
		// Verifica se está na parede
		if (IsOnWall()) {
			// Pulo na parede
			if (Input.IsActionJustPressed("pula") && !puloNaParede) {
				direcao.Y = altura_pulo; // Ajusta para o pulo padrão
				direcao.X = -direcao.X; // Inverte a direção horizontal
				
				// Permite pulo duplo na parede
				pulo_duplo = true;
				puloNaParede = true;
			}
		}

		//MOVIMENTO
		Velocity = new Vector2(direcao.X * velocidade, direcao.Y * gravidade);	
		MoveAndSlide();
	}
	
   public void IncrementarPontuacao(int valor){
		pontuacao += valor;
		GD.Print("Pontuação: " + pontuacao);
	}

	public void Morte() {
		GD.Print("Perdeu!");
		GetTree().ChangeSceneToFile("res://cenasFireboy/game_over!.tscn");
	}
	
	private void _on_coiote_timer_timeout()
	{
		podePularCoiote = false;
	}
}
