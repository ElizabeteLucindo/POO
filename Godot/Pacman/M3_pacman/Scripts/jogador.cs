using Godot;
using System;

public partial class jogador : CharacterBody2D
{
	private Vector2 direcao;
	private int moedasRestantes = 178;
	public int pontuacao { get; private set; } = 0;
	
	//export serve para exibir na interface do Godot
	[Export] private float velocidade = 180f;

	public void Controle() {
		direcao = Vector2.Zero;
		if ( Input.IsActionPressed("esquerda") ) {
			direcao.X = -1;
			
		}
		if ( Input.IsActionPressed("direita") ) {
			direcao.X = 1;
			
		}
		if ( Input.IsActionPressed("cima") ) {
			direcao.Y = -1;
			
		}
		if ( Input.IsActionPressed("baixo") ) {
			direcao.Y = 1;
			
		}
		
		
	}
	public override void _Process(double delta)
	{
		Controle(); //verifica as ações do controle
		Velocity = direcao * velocidade;
		MoveAndSlide();
	}

	//Essa função é chamada pela Pílula quando ela é coletada
	public void Pilula () {
		
		if ( GetNode<Timer>("Timer").TimeLeft != 0 ) {
			GD.Print("Nitro Aumentado!");
			GetNode<Timer>("Timer").Start(GetNode<Timer>("Timer").TimeLeft + 10);
		} else {
			velocidade *= 2; //dobra a velocidade
			GetNode<Timer>("Timer").Start();
			GD.Print("Nitro Ativo!");
		}
	}
	//Essa função é chamada pelo timer quando passam-se 5 segundos.
	public void FimPilula () {
		velocidade /= 2; //divide a velocidade por 2
		GetNode<Timer>("Timer").Stop();
		GD.Print("Fim do Nitro!");
	}
	
	public void IncrementarPontuacao(int valor){
		pontuacao += valor;
		GD.Print("Pontuação: " + pontuacao);
	}
	
	 public void VerificarMoedas()
	{
		moedasRestantes--; // Decrementa o contador de moedas restantes
		if (moedasRestantes <= 0)
		{
			GetTree().ChangeSceneToFile("res://Cenas/voce_ganhou.tscn");
			//GetTree().Quit();
		}

	}
}
