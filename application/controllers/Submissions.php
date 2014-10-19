<?php
/**
 * Sharif Judge online judge
 * @file Submissions.php
 * @author Mohammad Javad Naderi <mjnaderi@gmail.com>
 */
defined('BASEPATH') OR exit('No direct script access allowed');

class Submissions extends CI_Controller
{

	var $username;
	var $assignment;
	var $user_level;
	var $final_items;

	var $filter_user;
	var $filter_problem;
	var $page_number;

	// ------------------------------------------------------------------------


	public function __construct()
	{
		parent::__construct();
		$this->load->driver('session');
		if ( ! $this->session->userdata('logged_in')) // if not logged in
			redirect('login');
		$this->load->model('submit_model');
		$this->username = $this->session->userdata('username');
		$this->assignment = $this->assignment_model->assignment_info($this->user_model->selected_assignment($this->username));
		$this->user_level = $this->user_model->get_user_level($this->username);

		$input = $this->uri->uri_to_assoc();
		$this->filter_user = $this->filter_problem = NULL;
		$this->page_number = 1;
		if (array_key_exists('user', $input) && $input['user'])
			if ($this->user_level > 0) // students are not able to filter submissions by user
				$this->filter_user = $this->form_validation->alpha_numeric($input['user'])?$input['user']:NULL;
		if (array_key_exists('problem', $input) && $input['problem'])
			$this->filter_problem = is_numeric($input['problem'])?$input['problem']:NULL;
		if (array_key_exists('page', $input) && $input['page'])
			$this->page_number = is_numeric($input['page'])?$input['page']:1;

	}




	// ------------------------------------------------------------------------


	/**
	 * Uses PHPExcel library to generate excel file of submissions
	 */
	private function _download_excel($view)
	{
		if ( ! in_array($view, array('all', 'final')))
			exit;

		$now=date('Y-m-d H:i:s', shj_now()); // current time

		// Load PHPExcel library
		$this->load->library('phpexcel');

		// Set document properties
		$this->phpexcel->getProperties()->setCreator('Sharif Judge')
			->setLastModifiedBy('Sharif Judge')
			->setTitle('Sharif Judge Users')
			->setSubject('Sharif Judge Users')
			->setDescription('List of Sharif Judge users ('.$now.')');

		// Name of the file sent to browser
		$output_filename = 'judge_'.$view.'_submissions.xlsx';

		// Set active sheet
		$this->phpexcel->setActiveSheetIndex(0);
		$sheet = $this->phpexcel->getActiveSheet();

		// Add current assignment, time, username filter, and problem filter to document
		$sheet->fromArray(array('Assignment:',$this->assignment['name']), null, 'A1', true);
		$sheet->fromArray(array('Time:',$now), null, 'A2', true);
		$sheet->fromArray(array('Username Filter:', $this->filter_user?$this->filter_user:'No filter'), null, 'A3', true);
		$sheet->fromArray(array('Problem Filter:', $this->filter_problem?$this->filter_problem:'No filter'), null, 'A4', true);

		// Prepare header
		if ($this->user_level === 0)
			$header=array('Final','Problem','Submit Time','Score','Delay (HH:MM)','Coefficient','Final Score','Language','Status','#');
		else{
			$header=array('Final','Submit ID','Username','Name','Problem','Submit Time','Score','Delay (HH:MM)','Coefficient','Final Score','Language','Status','#');
			if ($view === 'final'){
				array_unshift($header, "#2");
				array_unshift($header, "#1");
			}
		}

		// Add header to document
		$sheet->fromArray($header, null, 'A6', true);
		$highest_column = $sheet->getHighestColumn();

		// Set custom style for header
		$sheet->getStyle('A6:'.$highest_column.'6')->applyFromArray(
			array(
				'fill' => array(
					'type' => PHPExcel_Style_Fill::FILL_SOLID,
					'color' => array('rgb' => '173C45')
				),
				'font'  => array(
					'bold'  => true,
					'color' => array('rgb' => 'FFFFFF'),
					//'size'  => 14
				)
			)
		);

		// Prepare data (in $rows array)
		if ($view === 'final')
			$items = $this->submit_model->get_final_submissions($this->assignment['id'], $this->user_level, $this->username, NULL, $this->filter_user, $this->filter_problem);
		else
			$items = $this->submit_model->get_all_submissions($this->assignment['id'], $this->user_level, $this->username, NULL, $this->filter_user, $this->filter_problem);
		$finish = strtotime($this->assignment['finish_time']);
		$i=0; $j=0; $un='';
		$rows = array();
		foreach ($items as $item){
			$i++;
			if ($item['username'] != $un)
				$j++;
			$un = $item['username'];
			if ( ! isset($name[$item['username']]))
				$name[$item['username']] = $this->user_model->get_user($item['username'])->display_name;

			$pi = $this->assignment_model->problem_info($this->assignment['id'], $item['problem']);

			$pre_score = ceil($item['pre_score']*$pi['score']/10000);

			$checked='';
			if ($view === 'all'){
				if (isset($this->final_items[$item['username']][$item['problem']]['submit_id']))
					if ($this->final_items[$item['username']][$item['problem']]['submit_id'] == $item['submit_id'])
						$checked='*';
			}
			else
				$checked='*';

			$delay = strtotime($item['time'])-$finish;
			if ($item['coefficient'] === 'error')
				$final_score = 0;
			else
				$final_score = ceil($pre_score*$item['coefficient']/100);

			if ($delay<0)
				$delay = 0;
			$delay /= 60;
			$h = floor($delay/60);
			$m = floor($delay%60);
			if ($h<10)
				$h="0$h";
			if ($m<10)
				$m="0$m";

			if ($this->user_level === 0)
				$row = array(
					$checked,
					$item['problem'].' ('.$pi['name'].')',
					$item['time'],
					$pre_score,
					$h.':'.$m,
					$item['coefficient'],
					$final_score,
					filetype_to_language($item['file_type']),
					$item['status'],
					$item['submit_count']
				);
			else {
				$row = array(
					$checked,
					$item['submit_id'],
					$item['username'],
					$name[$item['username']],
					$item['problem'].' ('.$pi['name'].')',
					$item['time'],
					$pre_score,
					$h.':'.$m,
					$item['coefficient'],
					$final_score,
					filetype_to_language($item['file_type']),
					$item['status'],
					$item['submit_count']
				);
				if ($view === 'final'){
					array_unshift($row,$j);
					array_unshift($row,$i);
				}
			}
			array_push($rows, $row);
		}

		// Add rows to document
		$sheet->fromArray($rows, null, 'A7', true);
		// Add alternative colors to rows
		for ($i=7; $i<count($rows)+7; $i++){
			$sheet->getStyle('A'.$i.':'.$highest_column.$i)->applyFromArray(
				array(
					'fill' => array(
						'type' => PHPExcel_Style_Fill::FILL_SOLID,
						'color' => array('rgb' => (($i%2)?'F0F0F0':'FAFAFA'))
					)
				)
			);
		}

		// Set text align to center
		$sheet->getStyle( $sheet->calculateWorksheetDimension() )
			->getAlignment()
			->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);

		// Making columns autosize
		for ($i=2;$i<count($header);$i++)
			$sheet->getColumnDimension(chr(65+$i))->setAutoSize(true);

		// Set Border
		$sheet->getStyle('A7:'.$highest_column.$sheet->getHighestRow())->applyFromArray(
			array(
				'borders' => array(
					'outline' => array(
						'style' => PHPExcel_Style_Border::BORDER_THIN,
						'color' => array('rgb' => '444444'),
					),
				)
			)
		);

		// Send the file to browser
		header('Content-Type: application/vnd.openxmlformats-officedocument.spreadsheetml.sheet');
		header('Content-Disposition: attachment;filename="'.$output_filename.'"');
		header('Cache-Control: max-age=0');
		$objWriter = PHPExcel_IOFactory::createWriter($this->phpexcel, 'Excel2007');
		$objWriter->save('php://output');
	}




	// ------------------------------------------------------------------------




	public function final_excel()
	{
		$this->_download_excel('final');
	}



	public function all_excel()
	{
		$final = $this->submit_model->get_final_submissions($this->assignment['id'], $this->user_level, $this->username, NULL, $this->filter_user, $this->filter_problem);
		$this->final_items = array();
		foreach ($final as $item){
			$this->final_items[$item['username']][$item['problem']] = $item;
		}
		$this->_download_excel('all');
	}




	// ------------------------------------------------------------------------




	public function the_final()
	{

		if ( ! is_numeric($this->page_number))
			show_404();

		if ($this->page_number<1)
			show_404();

		$config = array(
			'base_url' => site_url('submissions/final'.($this->filter_user?'/user/'.$this->filter_user:'').($this->filter_problem?'/problem/'.$this->filter_problem:'')),
			'cur_page' => $this->page_number,
			'total_rows' => $this->submit_model->count_final_submissions($this->assignment['id'], $this->user_level, $this->username, $this->filter_user, $this->filter_problem),
			'per_page' => $this->settings_model->get_setting('results_per_page_final'),
			'num_links' => 5,
			'full_ul_class' => 'shj_pagination',
			'cur_li_class' => 'current_page'
		);
		if ($config['per_page'] == 0)
			$config['per_page'] = $config['total_rows'];
		$this->load->library('shj_pagination', $config);

		$data = array(
			'view' => 'final',
			'username' => $this->username,
			'user_level' => $this->user_level,
			'all_assignments' => $this->assignment_model->all_assignments(),
			'assignment' => $this->assignment,
			'title' => 'Final Submissions',
			'style' => 'main.css',
			'items' => $this->submit_model->get_final_submissions($this->assignment['id'], $this->user_level, $this->username, $this->page_number, $this->filter_user, $this->filter_problem),
			'excel_link' => site_url('submissions/final_excel'.($this->filter_user?'/user/'.$this->filter_user:'').($this->filter_problem?'/problem/'.$this->filter_problem:'')),
			'filter_user' => $this->filter_user,
			'filter_problem' => $this->filter_problem
		);

		$this->load->view('templates/header', $data);
		$this->load->view('pages/submissions', $data);
		$this->load->view('templates/footer');
	}




	// ------------------------------------------------------------------------




	public function all()
	{

		$final = $this->submit_model->get_final_submissions($this->assignment['id'], $this->user_level, $this->username, NULL, $this->filter_user, $this->filter_problem);
		$this->final_items = array();
		foreach ($final as $item){
			$this->final_items[$item['username']][$item['problem']] = $item;
		}

		if ( ! is_numeric($this->page_number))
			show_404();

		if ($this->page_number < 1)
			show_404();

		$config = array(
			'base_url' => site_url('submissions/all'.($this->filter_user?'/user/'.$this->filter_user:'').($this->filter_problem?'/problem/'.$this->filter_problem:'')),
			'cur_page' => $this->page_number,
			'total_rows' => $this->submit_model->count_all_submissions($this->assignment['id'], $this->user_level, $this->username, $this->filter_user, $this->filter_problem),
			'per_page' => $this->settings_model->get_setting('results_per_page_all'),
			'num_links' => 5,
			'full_ul_class' => 'shj_pagination',
			'cur_li_class' => 'current_page'
		);
		if ($config['per_page']==0)
			$config['per_page'] = $config['total_rows'];
		$this->load->library('shj_pagination', $config);

		$data = array(
			'view' => 'all',
			'username' => $this->username,
			'user_level' => $this->user_level,
			'all_assignments' => $this->assignment_model->all_assignments(),
			'assignment' => $this->assignment,
			'title' => 'All Submissions',
			'style' => 'main.css',
			'items' => $this->submit_model->get_all_submissions($this->assignment['id'], $this->user_level, $this->username, $this->page_number, $this->filter_user, $this->filter_problem),
			'final_items' => $this->final_items,
			'excel_link' => site_url('submissions/all_excel'.($this->filter_user?'/user/'.$this->filter_user:'').($this->filter_problem?'/problem/'.$this->filter_problem:'')),
			'filter_user' => $this->filter_user,
			'filter_problem' => $this->filter_problem
		);
		$this->load->view('templates/header', $data);
		$this->load->view('pages/submissions', $data);
		$this->load->view('templates/footer');
	}




	// ------------------------------------------------------------------------




	/**
	 * Used by ajax request (for selecting final submission)
	 */
	public function select()
	{
		if ( ! $this->input->is_ajax_request() )
			show_404();

		// Students cannot change their final submission after finish_time + extra_time
		if ($this->user_level === 0)
			if ( shj_now() > strtotime($this->assignment['finish_time'])+$this->assignment['extra_time'])
				exit('shj_finished');

		$this->form_validation->set_rules('submit_id', 'Submit ID', 'integer|greater_than[0]');
		$this->form_validation->set_rules('problem', 'problem', 'integer|greater_than[0]');
		$this->form_validation->set_rules('username', 'Username', 'required|min_length[3]|max_length[20]|alpha_numeric');

		if ($this->form_validation->run())
		{
			$username = $this->input->post('username');
			if ($this->user_level === 0)
				$username = $this->username;

			$res = $this->submit_model->set_final_submission(
				$username,
				$this->assignment['id'],
				$this->input->post('problem'),
				$this->input->post('submit_id')
			);

			echo ($res?'shj_success':'shj_failed');

			if ($res) {
				// each time a users changes final submission, we should update scoreboard of that assignment
				$this->load->model('scoreboard_model');
				$this->scoreboard_model->update_scoreboard($this->assignment['id']);
			}
		}
	}




	// ------------------------------------------------------------------------



        /*
         * status of the code submitted
         */
	public function status()
	{
            if ( ! $this->input->is_ajax_request() )
			show_404();
            $problem_id = $this->input->post('problem_id');
            $submit_id = $this->input->post('submit_id');
            $username = $this->input->post('username');
            $this->load->model('queue_model');
            $data  = new stdClass();

            if($this->queue_model->in_queue($username, $this->assignment['id'], $problem_id)) {
                $data->status = "pending";
            }
            else {
                $submission = $this->submit_model->get_submission($username, $this->assignment['id'], $problem_id, $submit_id);
                $data->style_class = status_to_class($submission['status'], $submission['pre_score']);
                $data->status = $submission['status'];
                $problem = $this->assignment_model->problem_info($this->assignment['id'],$problem_id);
                $data->score = ceil($submission['pre_score']*$problem['score']/10000);
            }
 
            echo json_encode($data);
        }

        /**
	 * For "view code" or "view result" or "view log"
	 */
	public function view_code()
	{
		if ( ! $this->input->is_ajax_request() )
			show_404();
		$this->form_validation->set_rules('code','code','integer|greater_than_equal_to[0]|less_than_equal_to[2]');
		$this->form_validation->set_rules('username','username','required|min_length[3]|max_length[20]|alpha_numeric|xss_clean');
		$this->form_validation->set_rules('assignment','assignment','integer|greater_than[0]');
		$this->form_validation->set_rules('problem','problem','integer|greater_than[0]');
		$this->form_validation->set_rules('submit_id','submit_id','integer|greater_than[0]');
		if($this->form_validation->run()){
			$submission = $this->submit_model->get_submission(
				$this->input->post('username'),
				$this->input->post('assignment'),
				$this->input->post('problem'),
				$this->input->post('submit_id')
			);
			if ($submission === FALSE)
				show_404();

			/*
			 * $this->input->post('code'):
			 *   0 => result
			 *   1 => code
			 *   2 => log
			 */

			if ($this->user_level === 0 && $this->input->post('code') == 2)
				show_404();

			if ($this->user_level === 0 && $this->username != $submission['username'])
				exit('Don\'t try to see submitted codes :)');

			$code = $this->input->post('code');

			if ($code==0)
				$file_path = rtrim($this->settings_model->get_setting('assignments_root'),'/').
					"/assignment_{$submission['assignment']}/p{$submission['problem']}/{$submission['username']}/result-{$submission['submit_id']}.html";
			elseif ($code==1)
				$file_path = rtrim($this->settings_model->get_setting('assignments_root'),'/').
					"/assignment_{$submission['assignment']}/p{$submission['problem']}/{$submission['username']}/{$submission['file_name']}.".filetype_to_extension($submission['file_type']);
			elseif ($code==2)
				$file_path = rtrim($this->settings_model->get_setting('assignments_root'),'/').
					"/assignment_{$submission['assignment']}/p{$submission['problem']}/{$submission['username']}/log";

			$data = array(
				'file_path'=>$file_path,
				'file_type'=>$submission['file_type'],
				'file_name'=>$submission['main_file_name'].'.'.filetype_to_extension($submission['file_type']),
				'view_username'=>$submission['username'],
				'view_assignment'=>$this->assignment_model->assignment_info($submission['assignment']),
				'view_problem'=>$this->assignment_model->problem_info($submission['assignment'], $submission['problem']),
				'code'=>$code
			);


			$data['log'] = FALSE;
			if($this->input->post('code')==2)
				$data['log'] = TRUE;

			$this->load->view('pages/view_code',$data);
		}
		else{
			exit('Are you trying to see other users\' codes? :)');
		}
	}




	// ------------------------------------------------------------------------




	public function download_file(){
		$username = $this->security->xss_clean($this->uri->segment(3));
		$assignment = $this->security->xss_clean($this->uri->segment(4));
		$problem = $this->security->xss_clean($this->uri->segment(5));
		$submit_id = $this->security->xss_clean($this->uri->segment(6));

		$submission = $this->submit_model->get_submission(
			$username,
			$assignment,
			$problem,
			$submit_id
		);
		if ($submission === FALSE)
			show_404();

		if ($this->user_level === 0 && $this->username != $submission['username'])
			exit('Don\'t try to see submitted codes :)');

		$file_path = rtrim($this->settings_model->get_setting('assignments_root'),'/').
		"/assignment_{$submission['assignment']}/p{$submission['problem']}/{$submission['username']}/{$submission['file_name']}.".filetype_to_extension($submission['file_type']);

		$this->load->helper('download');
		force_download(
			"{$submission['file_name']}.".filetype_to_extension($submission['file_type']),
			file_get_contents($file_path)
		);

	}


}