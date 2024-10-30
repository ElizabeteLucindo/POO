using Godot;
using System;

public partial class fantasma : CharacterBody2D
{
	private Vector2 direcao;
	private bool naArea = false;
	//export serve para exibir na interface do Godot
	[Export] private float velocidade = 100f;

	public void Controle()
	{
		direcao = Vector2.Zero;
		Random rnd = new Random();
		
		direcao.X = rnd.Next(-1, 2);
		direcao.Y = rnd.Next(-1, 2);
		GD.Print(direcao);
		
	}
	
	public override void _Process(double delta)
	{
		//Controle(); //verifica as ações do controle
		Velocity = direcao * velocidade;
		MoveAndSlide();
	}

	private void matou(Node2D body)
{
	if (body is jogador)
	{
		GD.Print("Jogador morto");
		GetTree().ChangeSceneToFile("res://Cenas/game_over.tscn");
		//GetTree().Quit(); // Encerra o jogo
	}
	else
	{
		GD.Print("Objeto não é um jogador.");
	}
}

	
	private void visao(Node2D body)
	{
		naArea = true;
	}
	
	private void saiuVisao(Node2D body)
	{
		naArea = false;
	}
	
	private void ativaMovimento()
	{
		Controle();
	}
}
