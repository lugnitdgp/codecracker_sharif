<?php
/**
 * Sharif Judge online judge
 * @file Server_time.php
 * @author Mohammad Javad Naderi <mjnaderi@gmail.com>
 */
defined('BASEPATH') OR exit('No direct script access allowed');

class Server_time extends CI_Controller
{

	public function __construct()
	{
		parent::__construct();
		$this->load->driver('session');
		if ( ! $this->input->is_ajax_request() )
			show_404();
		if ( ! $this->session->userdata('logged_in')) // if not logged in
			exit;
	}


	// ------------------------------------------------------------------------


	/**
	 * Prints server time, used for server time synchronization
	 */
	public function index()
	{
		echo date("Y-m-d H:i:s", shj_now());
	}
}